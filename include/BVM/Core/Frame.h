#pragma once

#include <stack>
#include <memory>

#include <BVM/Object/Object.h>
#include <BVM/Object/CodeObject.h>

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
			Frame* getPrevFrame();
			std::shared_ptr<Object::CodeObject> getCode();

			// Stack operations
			void push(std::shared_ptr<Object::IObject> obj);
			std::shared_ptr<Object::IObject> top();
			std::shared_ptr<Object::IObject> pop();

			// Code object operations
			const Instruction& next();
			const Instruction& jump(size_t shift);

		private:
			Frame* _prevFrame; // The pointer to a previous frame in call stack
			std::shared_ptr<Object::CodeObject> _code; // The shared pointer to code object which is executed in this frame
			size_t _depth; // The frame call depth

			std::stack<std::shared_ptr<Object::IObject>> _stack;

			size_t _index; // Current instruction index
		};
	}
}