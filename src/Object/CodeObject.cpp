#include "CodeObject.h"
#include <BVM/Object/CodeObject.h>

namespace BVM
{
	namespace Object
	{
		CodeObject::CodeObject(const Core::Bytecode& bytecode, const std::vector<std::shared_ptr<IObject>>& constants)
			: _bytecode(bytecode), _constants(constants)
		{}

		const Core::Bytecode& CodeObject::getBytecode() const
		{
			return _bytecode;
		}

		const Core::Instruction& CodeObject::getInstruction(size_t index) const
		{
			return _bytecode[index];
		}

		const std::shared_ptr<IObject>& CodeObject::getConstant(size_t index) const
		{
			return _constants[index];
		}
	}
}