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
			Frame(std::shared_ptr<Object::CodeObject> code, size_t depth);
			Frame(std::shared_ptr<Object::CodeObject> code, Frame* _prev, size_t depth);
			~Frame() = default;

			Frame* gerPrevFrame();
			std::shared_ptr<Object::CodeObject> getCode();

			void push(std::shared_ptr<Object::IObject> obj);
			std::shared_ptr<Object::IObject> pop();

		private:
			Frame* _prevFrame;
			std::shared_ptr<Object::CodeObject> _code;
			size_t _depth;

			std::stack<std::shared_ptr<Object::IObject>> _stack;
		};
	}
}