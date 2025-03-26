#pragma once

#include <stack>
#include <memory>

#include <BVM/Object/Object.h>
#include <BVM/Object/CodeObject.h>

#include <BVM/Core/Instruction.h>

namespace BVM
{
	namespace Core
	{
		class Frame
		{
		public:
			// Constructors & Destructors
			Frame(std::shared_ptr<Object::CodeObject> code, size_t depth);
			Frame(std::shared_ptr<Object::CodeObject> code, Frame* _prev, size_t depth);
			~Frame() = default;

			// Getters
			Frame* getPrevFrame() const;
			std::shared_ptr<Object::IObject> getArgument(size_t index) const;
			std::shared_ptr<Object::CodeObject> getCode() const;
			size_t depth() const;

			// Setters
			void setPrevFrame(Frame* frame);
			void setArgument(size_t index, const std::shared_ptr<Object::IObject>& obj);

			// Stack operations
			void push(const std::shared_ptr<Object::IObject>& obj);
			void pushConst(size_t index);
			void pushArg(size_t index);

			std::shared_ptr<Object::IObject> top();
			std::shared_ptr<Object::IObject> pop();

			// Locals operations
			void load(size_t index);
			void store(size_t index);

			// Code object operations
			const Instruction& next();
			const Instruction& jump(size_t shift);

		private:
			Frame* _prevFrame; // The pointer to a previous frame in call stack
			std::shared_ptr<Object::CodeObject> _code; // The shared pointer to code object which is executed in this frame
			size_t _depth; // The frame call depth

			std::stack<std::shared_ptr<Object::IObject>> _stack; // Stack of objects in the frame
			std::unique_ptr<std::shared_ptr<Object::IObject>[]> _locals; // Array of local variables in the frame
			std::unique_ptr<std::shared_ptr<Object::IObject>[]> _arguments; // Array of local argument variables in the frame

			size_t _index; // Current instruction index
		};
	}
}