#include <BVM/Object/CodeObject.h>
#include <BVM/Core/Exceptions.h>

namespace BVM
{
	namespace Object
	{
		CodeObject::CodeObject(const Core::Bytecode& bytecode, const std::vector<std::shared_ptr<IObject>>& constants, size_t localsNum)
			: _bytecode(bytecode), _constants(constants), _localsNum(localsNum)
		{}

		const Core::Bytecode& CodeObject::getBytecode() const
		{
			return _bytecode;
		}

		const Core::Instruction& CodeObject::getInstruction(size_t index) const
		{
			if (index >= _bytecode.length())
			{
				throw Core::OutOfBoundsException("Instruction index " + std::to_string(index) + " is out of bounds.");
			}

			return _bytecode[index];
		}

		const std::shared_ptr<IObject>& CodeObject::getConstant(size_t index) const
		{
			if (index >= _constants.size())
			{
				throw Core::OutOfBoundsException("Constant index " + std::to_string(index) + " is out of bounds.");
			}

			return _constants[index];
		}

		size_t CodeObject::getLocalsNum() const
		{
			return _localsNum;
		}

		std::shared_ptr<IObject> CodeObject::add(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Addition is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::subtract(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Subtraction is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::multiply(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Multiplication is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::divide(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Division is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::equal(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Equality comparison is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::notEqual(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Inequality comparison is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::greater(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Greater comparison is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::greaterOrEqual(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("GreaterOrEqual comparison is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::less(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Less comparison is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::lessOrEqual(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("LessOrEqual comparison is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::logicalAnd(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Logical AND is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::logicalOr(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Logical OR is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::logicalXor(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Logical XOR is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::logicalNot() const
		{
			throw Core::InvalidOperationException("Logical NOT is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::negate() const
		{
			throw Core::InvalidOperationException("Negating is not supported for CodeObject.");
		}

		std::shared_ptr<IObject> CodeObject::clone() const
		{
			return std::make_shared<CodeObject>(_bytecode, _constants, _localsNum);
		}

		std::size_t CodeObject::hash() const
		{
			return std::size_t(0); // TODO: Implement hashing of code object
		}

		std::string CodeObject::typeName() const
		{
			return "CodeObject";
		}

		bool CodeObject::isType(const std::string& type) const
		{
			return type == "CodeObject";
		}

		std::string CodeObject::toString() const
		{
			return "CodeObject(locals=" + std::to_string(_localsNum) + ", constants=" + std::to_string(_constants.size()) + ")";
		}

	}
}
