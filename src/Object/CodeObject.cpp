#include <BVM/Object/CodeObject.h>
#include <BVM/Core/Exceptions.h>

namespace BVM
{
	namespace Object
	{
		CodeObject::CodeObject(Core::Bytecode&& bytecode, std::vector<std::shared_ptr<IObject>>&& constants, std::vector<std::string>&& names, size_t localsNum, size_t argumentsNum)
			: _bytecode(std::move(bytecode)),
			_constants(std::move(constants)),
			_names(std::move(names)),
			_localsNum(localsNum),
			_argumentsNum(argumentsNum)
		{}

		const Core::Bytecode& CodeObject::getBytecode() const
		{
			return _bytecode;
		}

		const Core::Instruction& CodeObject::getInstruction(size_t index) const
		{
			if (index >= _bytecode.length())
				throw Core::OutOfBoundsException("Instruction index " + std::to_string(index) + " is out of bounds");

			return _bytecode[index];
		}

		const std::shared_ptr<IObject>& CodeObject::getConstant(size_t index) const
		{
			if (index >= _constants.size())
				throw Core::OutOfBoundsException("Constant index " + std::to_string(index) + " is out of bounds");

			return _constants[index];
		}

		const std::string& CodeObject::getName(size_t index) const
		{
			if (index >= _names.size())
				throw Core::OutOfBoundsException("Name index " + std::to_string(index) + " is out of bounds");

			return _names[index];
		}

		size_t CodeObject::getLocalsNum() const
		{
			return _localsNum;
		}

		size_t CodeObject::getArgumentsNum() const
		{
			return _argumentsNum;
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
			return "CodeObject(constants=" + std::to_string(_constants.size()) + ", arguments=" + std::to_string(_argumentsNum), ", locals = " + std::to_string(_localsNum) + ")";
		}
	}
}