#pragma once

#include <memory>

#include <BVM/Core/Instruction.h>
#include <BVM/Core/Frame.h>

#include <BVM/Object/CodeObject.h>

namespace BVM
{
	namespace Core
	{
		class VM
		{
		public:
			VM(const std::shared_ptr<Object::CodeObject>& code);
			~VM();

			void run();
			void executeInstruction(const Instruction& instruction);
		private:
			// VM frames
			Frame* _rootFrame;
			Frame* _currentFrame;

			// VM states
			bool _isRunning;

			// Framge management
			void _popFrame();
			void _pushFrame(Frame* frame);
		};
	}
}