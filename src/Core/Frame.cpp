#include <BVM/Core/Frame.h>

namespace BVM
{
	namespace Core
	{
		Frame::Frame(std::shared_ptr<Object::CodeObject> code, size_t depth)
			: _code(code), _prevFrame(nullptr), _depth(depth)
		{}
		Frame::Frame(std::shared_ptr<Object::CodeObject> code, Frame* prev, size_t depth)
			: _code(code), _prevFrame(prev), _depth(depth)
		{}

		Frame* Frame::gerPrevFrame()
		{
			return _prevFrame;
		}

		std::shared_ptr<Object::CodeObject> Frame::getCode()
		{
			return _code;
		}

		void Frame::push(std::shared_ptr<Object::IObject> obj)
		{
			_stack.push(obj);
		}

		std::shared_ptr<Object::IObject> Frame::pop()
		{
			std::shared_ptr<Object::IObject> top = _stack.top();

			_stack.pop();

			return top;
		}
	}
}