#pragma once

#include <vector>
#include <memory>

#include <BVM/Core/Bytecode.h>
#include <BVM/Object/Object.h>

namespace BVM
{
	namespace Object
	{
		class CodeObject : IObject
		{
		public:
			CodeObject(const Core::Bytecode& bytecode, const std::vector<std::shared_ptr<IObject>>& constants);

			const Core::Bytecode& getBytecode() const;

			const Core::Instruction& getInstruction(size_t index) const;
			const std::shared_ptr<IObject>& getConstant(size_t index) const;

		private:
			Core::Bytecode _bytecode;
			std::vector<std::shared_ptr<IObject>> _constants; // Array of code constants
		};
	}
}