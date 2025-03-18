#include <BVM/Core/Bytecode.h>

#include <string>

#include <BVM/Core/Exceptions.h>

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
			if (index >= length())
				throw InstructionsOverException("The instruction with the " + std::to_string(index) + " index was not found");

			return _bytecode[index];
		}
	}
}