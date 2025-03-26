#include <BVM/Core/Frame.h>

#include <string>

#include <BVM/Core/Exceptions.h>

namespace BVM
{
	namespace Core
	{
		// Constructors & Destructors
		Frame::Frame(std::shared_ptr<Object::CodeObject> code, size_t depth)
			: _code(code), _prevFrame(nullptr), _depth(depth), _index(0),
			_locals(std::make_unique<std::shared_ptr<Object::IObject>[]>(_code->getLocalsNum())),
			_arguments(std::make_unique<std::shared_ptr<Object::IObject>[]>(_code->getArgumentsNum()))
		{}

		Frame::Frame(std::shared_ptr<Object::CodeObject> code, Frame* prev, size_t depth)
			: _code(code), _prevFrame(prev), _depth(depth), _index(0),
			_locals(std::make_unique<std::shared_ptr<Object::IObject>[]>(_code->getLocalsNum())),
			_arguments(std::make_unique<std::shared_ptr<Object::IObject>[]>(_code->getArgumentsNum()))
		{}

		// Getters
		Frame* Frame::getPrevFrame() const
		{
			return _prevFrame;
		}

		std::shared_ptr<Object::IObject> Frame::getArgument(size_t index) const
		{
			if (index >= _code->getArgumentsNum())
				throw ArgumentException(index, _code->getArgumentsNum() - 1);
			
			return _arguments[index];
		}

		std::shared_ptr<Object::CodeObject> Frame::getCode() const
		{
			return _code;
		}

		size_t Frame::depth() const
		{
			return _depth;
		}

		// Setters
		void Frame::setPrevFrame(Frame* frame)
		{
			_prevFrame = frame;
		}

		void Frame::setArgument(size_t index, const std::shared_ptr<Object::IObject>& obj)
		{
			if (index >= _code->getArgumentsNum())
				throw ArgumentException(index, _code->getArgumentsNum() - 1);
			
			_arguments[index] = obj;
		}

		// Stack operations
		void Frame::push(const std::shared_ptr<Object::IObject>& obj)
		{
			_stack.push(obj);
		}

		void Frame::pushConst(size_t index)
		{
			_stack.push(_code->getConstant(index));
		}

		void Frame::pushArg(size_t index)
		{
			if (index >= _code->getArgumentsNum())
				throw Core::OutOfBoundsException("Argument index " + std::to_string(index) + " is out of bounds");
			
			_stack.push(_arguments[index]);
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

		// Locals operations
		void Frame::load(size_t index)
		{
			if (index >= _code->getLocalsNum())
				throw LocalsException("Local variable with index " + std::to_string(index) + " was not found");

			_stack.push(_locals[index]);
		}

		void Frame::store(size_t index)
		{
			if (index >= _code->getLocalsNum())
				throw LocalsException("Local variable with index " + std::to_string(index) + " was not found");

			std::shared_ptr<Object::IObject> obj = _stack.top();

			_stack.pop();

			_locals[index] = obj;
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