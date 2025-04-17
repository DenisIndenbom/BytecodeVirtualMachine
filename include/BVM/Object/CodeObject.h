#pragma once

#include <cstdint>

#include <memory>
#include <string>
#include <vector>

#include <BVM/Core/Bytecode.h>
#include <BVM/Object/Object.h>

namespace BVM
{
	namespace Object
	{
		class CodeObject : public IObject
		{
		public:
			explicit CodeObject(Core::Bytecode&& bytecode,
				std::vector<std::shared_ptr<IObject>>&& constants,
				std::vector<std::string>&& names,
				std::vector<size_t>&& jumpPoints,
				size_t localsNum = 0,
				size_t argumentsNum = 0);

			// Getters
			const Core::Bytecode& getBytecode() const;
			const Core::Instruction& getInstruction(size_t index) const;
			const std::shared_ptr<IObject>& getConstant(size_t index) const;
			const std::string& getName(size_t index) const;
			size_t getJumpPoint(size_t index) const;
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
			std::vector<std::string> _names; // Vector of names in the code
			std::vector<size_t> _jumpPoints; // Vector of jump points in the bytecode

			size_t _localsNum; // Number of local variables in the code
			size_t _argumentsNum; // Number of argument variables in the code
		};
	}
}
