#include "Bytecode.h"
#include <BVM/Core/Bytecode.h>

namespace BVM
{
	namespace Core
	{
		Bytecode::Bytecode() {}

		size_t Bytecode::length() const
		{
			return _bytecode.size();
		}

		void Bytecode::add(const Instruction& instruction)
		{
			_bytecode.push_back(instruction);
		}

		const Instruction& Bytecode::operator[](size_t index) const
		{
			return _bytecode[index];
		}
	}
}