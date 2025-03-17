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
			if (index > length())
				return Instruction(InstructionType::HALT, NULL); // Return a HALT instruction if index is out of range 

			return _bytecode[index];
		}
	}
}