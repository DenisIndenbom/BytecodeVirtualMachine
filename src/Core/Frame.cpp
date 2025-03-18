#include <BVM/Core/Frame.h>

namespace BVM
{
	namespace Core
	{
		// Constructors & Destructors
		Frame::Frame(std::shared_ptr<Object::CodeObject> code, size_t depth)
			: _code(code), _prevFrame(nullptr), _depth(depth), _index(0)
		{}

		Frame::Frame(std::shared_ptr<Object::CodeObject> code, Frame* prev, size_t depth)
			: _code(code), _prevFrame(prev), _depth(depth), _index(0)
		{}

		// Getters
		Frame* Frame::getPrevFrame()
		{
			return _prevFrame;
		}

		std::shared_ptr<Object::CodeObject> Frame::getCode()
		{
			return _code;
		}

		void Frame::setPrevFrame(Frame* frame)
		{
			_prevFrame = frame;
		}

		// Stack operations
		void Frame::push(std::shared_ptr<Object::IObject> obj)
		{
			_stack.push(obj);
		}

		void Frame::pushConst(size_t index)
		{
			_stack.push(_code->getConstant(index));
		}

		std::shared_ptr<Object::IObject> Frame::top()
		{
			return _stack.top();
		}

		std::shared_ptr<Object::IObject> Frame::pop()
		{
			std::shared_ptr<Object::IObject> top = _stack.top();

			_stack.pop();

			return top;
		}

		// Code object operations
		const Instruction& Frame::next()
		{
			return _code->getBytecode()[_index++];
		}

		const Instruction& Frame::jump(size_t shift)
		{
			_index += shift;

			return _code->getBytecode()[_index];
		}


	}
}