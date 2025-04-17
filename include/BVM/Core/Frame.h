#pragma once

#include <memory>
#include <stack>
#include <vector>

#include <BVM/Object/CodeObject.h>
#include <BVM/Object/Object.h>

#include <BVM/Core/Instruction.h>

namespace BVM
{
	namespace Core
	{
		class Frame
		{
		public:
			// Constructors & Destructors
			Frame(std::shared_ptr<Object::CodeObject> code, size_t depth = 0);
			Frame(std::shared_ptr<Object::CodeObject> code, const std::shared_ptr<Frame>& prev, size_t depth = 0);
			Frame(std::shared_ptr<Object::CodeObject> code,
				const std::shared_ptr<Frame>& prev,
				std::vector<std::shared_ptr<Object::IObject>>&& args,
				size_t depth = 0);

			~Frame() = default;

			// Getters
			std::shared_ptr<Frame> getPrevFrame() const noexcept;
			std::shared_ptr<Object::CodeObject> getCode() const noexcept;
			size_t depth() const;

			// Setters
			void setPrevFrame(const std::shared_ptr<Frame>& frame);

			// Stack operations
			void push(const std::shared_ptr<Object::IObject>& obj);
			void push(std::shared_ptr<Object::IObject>&& obj);
			void pushConst(size_t index);
			void pushArg(size_t index);

			[[nodiscard]] std::shared_ptr<Object::IObject> top();
			[[nodiscard]] std::shared_ptr<Object::IObject> pop();

			// Locals operations
			void load(size_t index);
			void store(size_t index);

			// Code object operations
			[[nodiscard]]  const Instruction& next();
			void jump(size_t index);

		private:
			std::shared_ptr<Frame> _prevFrame; // The shared pointer to a previous frame in call stack
			std::shared_ptr<Object::CodeObject> _code; // The shared pointer to code object which is executed in this frame
			size_t _depth; // The frame call depth

			std::stack<std::shared_ptr<Object::IObject>> _stack; // Stack of objects in the frame
			std::vector<std::shared_ptr<Object::IObject>> _locals; // Array of local variables in the frame
			std::vector<std::shared_ptr<Object::IObject>> _arguments; // Array of local argument variables in the frame

			size_t _index = 0; // Current instruction index
		};
	}
}