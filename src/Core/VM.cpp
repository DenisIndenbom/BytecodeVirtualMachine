#include <BVM/Core/Instruction.h>
#include <BVM/Core/VM.h>

namespace BVM
{
	namespace Core
	{
		VM::VM(const std::shared_ptr<Object::CodeObject>& code) : _rootFrame(new Frame(code, 0)), _currentFrame(_rootFrame) {}

		VM::~VM()
		{
			do
			{
				_popFrame();
			} while (_currentFrame != _rootFrame);
		}

		void VM::run()
		{
			while (_currentFrame != nullptr)
			{
				const Instruction& instrunction = _currentFrame->next();

				if (instrunction.type == InstructionType::HALT)
				{
					_popFrame();

					continue;
				}

				executeInstruction(instrunction);
			}
		}

		void VM::executeInstruction(const Instruction& instruction)
		{
			switch (instruction.type)
			{
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


	}
}