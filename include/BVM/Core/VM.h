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
			Frame* _rootFrame;
			Frame* _currentFrame;
		};
	}
}