#include <BVM/Core/VM.h>

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
					break;
				}
			}
		}

		void VM::executeInstruction(const Instruction& instruction)
		{
			switch (instruction.type)
			{
			case InstructionType::PUSH_CONST:
			{
				_currentFrame->pushConst(instruction.arg);
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

	}
}