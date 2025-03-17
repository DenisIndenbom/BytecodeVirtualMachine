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
				Frame* prev = _currentFrame->gerPrevFrame();

				delete _currentFrame;

				_currentFrame = prev;

			} while (_currentFrame != _rootFrame)
		}

		void VM::run()
		{
			while (true)
			{
				// run virtual machine
			}
		}

		void VM::executeInstruction(const Instruction& instruction)
		{
			// Not implemented yet
		}


	}
}