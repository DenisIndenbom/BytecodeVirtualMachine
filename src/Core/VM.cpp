#include <BVM/Core/Instruction.h>
#include <BVM/Core/VM.h>

namespace BVM
{
	namespace Core
	{
		VM::VM(const std::shared_ptr<Object::CodeObject>& code) : _rootFrame(new Frame(code, 0)), _currentFrame(_rootFrame) {}

		VM::~VM()
		{
			while (_currentFrame != nullptr)
				_popFrame();
		}

		void VM::run()
		{
			while (_currentFrame != nullptr)
			{
				executeInstruction(_currentFrame->next());
			}
		}

		void VM::executeInstruction(const Instruction& instruction)
		{
			switch (instruction.type)
			{
			case InstructionType::HALT:
				_popFrame();
				break;
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