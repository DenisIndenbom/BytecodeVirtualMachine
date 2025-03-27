#pragma once

#include <vector>
#include <memory>

#include <BVM/Core/Bytecode.h>
#include <BVM/Object/Object.h>

namespace BVM
{
	namespace Object
	{
		class CodeObject : public IObject
		{
		public:
			explicit CodeObject(Core::Bytecode&& bytecode, std::vector<std::shared_ptr<IObject>>&& constants, size_t localsNum = 0, size_t argumentsNum = 0);

			// Getters
			const Core::Bytecode& getBytecode() const;
			const Core::Instruction& getInstruction(size_t index) const;
			const std::shared_ptr<IObject>& getConstant(size_t index) const;
			size_t getLocalsNum() const;
			size_t getArgumentsNum() const;

			// Type information
			std::size_t hash() const override;

			std::string typeName() const override;

			bool isType(const std::string& type) const override;
			std::string toString() const override;

		private:
			Core::Bytecode _bytecode; // Executable byte code
			std::vector<std::shared_ptr<IObject>> _constants; // Vector of constants in the code
			size_t _localsNum; // Number of local variables in the code
			size_t _argumentsNum; // Number of argument variables in the code
		};
	}
}
