#include <BVM/Core/VM.h>

#include <iostream>
#include <memory>

#include <BVM/Core/Instruction.h>
#include <BVM/Core/Exceptions.h>
#include <BVM/Object/Object.h>

namespace BVM
{
	namespace Core
	{
		VM::VM(const std::shared_ptr<Object::CodeObject>& code) : _rootFrame(new Frame(code, 0)), _currentFrame(_rootFrame), _isRunning(true) {}

		VM::~VM()
		{
			while (_currentFrame != nullptr)
				_popFrame();
		}

		void VM::run()
		{
			while (_currentFrame != nullptr && _isRunning)
			{
				try
				{
					executeInstruction(_currentFrame->next());
				}
				catch (Exception e)
				{
					std::cout << e.what();

					break;
				}
			}
		}

		void VM::executeInstruction(const Instruction& instruction)
		{
			switch (instruction.type)
			{
				// Stack operations
			case InstructionType::PUSH_CONST:
			{
				_currentFrame->pushConst(instruction.arg);

				break;
			}
			case InstructionType::POP:
			{
				_currentFrame->pop();

				break;
			}
			case InstructionType::DUP:
			{
				std::shared_ptr<Object::IObject> top = _currentFrame->top();

				_currentFrame->push(top); // Duplicate element

				break;
			}
			case InstructionType::SWAP:
			{
				std::shared_ptr<Object::IObject> first = _currentFrame->top();
				std::shared_ptr<Object::IObject> second = _currentFrame->top();

				// Swap elements of the stack
				_currentFrame->push(first);
				_currentFrame->push(second);

				break;
			}
			case InstructionType::ROT:
			{
				std::shared_ptr<Object::IObject> first = _currentFrame->top();
				std::shared_ptr<Object::IObject> second = _currentFrame->top();
				std::shared_ptr<Object::IObject> third = _currentFrame->top();

				// Swap the first and the third elements of the stack
				_currentFrame->push(first);
				_currentFrame->push(second);
				_currentFrame->push(third);

				break;
			}
			case InstructionType::OVER:
			{
				std::shared_ptr<Object::IObject> first = _currentFrame->top();
				std::shared_ptr<Object::IObject> second = _currentFrame->top();

				// Keep the same order
				_currentFrame->push(second);
				_currentFrame->push(first);

				// Copy the second element from the top of the stack
				_currentFrame->push(second);

				break;
			}
			// Math operations
			case InstructionType::ADD:
			{
				_binaryOp([](auto lhs, auto rhs) { return lhs->add(rhs); });

				break;
			}
			case InstructionType::SUB:
			{
				_binaryOp([](auto lhs, auto rhs) { return lhs->subtract(rhs); });

				break;
			}
			case InstructionType::MUL:
			{
				_binaryOp([](auto lhs, auto rhs) { return lhs->multiply(rhs); });

				break;
			}
			case InstructionType::DIV:
			{
				_binaryOp([](auto lhs, auto rhs) { return lhs->divide(rhs); });

				break;
			}
			// Control Flow
			case InstructionType::CALL:
			{
				std::shared_ptr<Object::CodeObject> codeObj = std::dynamic_pointer_cast<Object::CodeObject>(_currentFrame->top());

				if (!codeObj)
					throw TypeException("Object is not callable");

				_currentFrame = new Frame(codeObj, _currentFrame, _currentFrame->depth());

				break;
			}
			case InstructionType::RETURN:
			{
				std::shared_ptr<Object::IObject> obj = _currentFrame->pop();

				_popFrame();

				if (_currentFrame == nullptr)
					break; // Exit from switch if program returned from the last frame

				_currentFrame->push(obj);

				break;
			}
			case InstructionType::PRINT:
			{
				std::cout << _currentFrame->pop()->toString() << '\n';

				break;
			}
			// Debugging/Utility
			case InstructionType::HALT:
			{
				_isRunning = false; // Change the running state to false

				break;
			}
			default:
				break;
			}
		}

		void VM::_popFrame()
		{
			Frame* prev = _currentFrame->getPrevFrame();

			delete _currentFrame;

			_currentFrame = prev;
		}

		void VM::_pushFrame(Frame* frame)
		{
			frame->setPrevFrame(_currentFrame);
			_currentFrame = frame;
		}

		void VM::_unaryOp(std::shared_ptr<Object::IObject>(*operation)(std::shared_ptr<Object::IObject>))
		{
			std::shared_ptr<Object::IObject> top = _currentFrame->pop();

			_currentFrame->push(operation(top));
		}

		void VM::_binaryOp(std::shared_ptr<Object::IObject>(*operation)(std::shared_ptr<Object::IObject>, std::shared_ptr<Object::IObject>))
		{
			std::shared_ptr<Object::IObject> rhs = _currentFrame->pop();
			std::shared_ptr<Object::IObject> lhs = _currentFrame->pop();

			_currentFrame->push(operation(lhs, rhs));
		}

	}
}