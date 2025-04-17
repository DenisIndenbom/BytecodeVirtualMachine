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
			std::shared_ptr<Frame> _rootFrame; // Root frame
			std::shared_ptr<Frame> _currentFrame; // Current frame

			// VM states
			bool _isRunning = true;

			// Frame management
			void _popFrame();
			void _pushFrame(const std::shared_ptr<Frame>& frame);

			// Operation handlers
			void _unaryOp(std::shared_ptr<Object::IObject>(*operation)(std::shared_ptr<Object::IObject>));
			void _binaryOp(std::shared_ptr<Object::IObject>(*operation)(std::shared_ptr<Object::IObject>, std::shared_ptr<Object::IObject>));
		};
	}
}