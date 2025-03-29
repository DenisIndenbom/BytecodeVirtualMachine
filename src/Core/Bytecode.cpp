#include <BVM/Core/Bytecode.h>

#include <string>
#include <utility>

#include <BVM/Core/Exceptions.h>

namespace BVM
{
	namespace Core
	{
		Bytecode::Bytecode(std::vector<Instruction>&& instructions) : _instructions(std::move(instructions)) {}

		Bytecode::Bytecode(const std::initializer_list<Instruction>& instructions) : _instructions(std::vector<Instruction>(instructions.size()))
		{
			std::copy(instructions.begin(), instructions.end(), _instructions.begin());
		}

		Bytecode::Bytecode(const Bytecode& other) : _instructions(std::vector<Instruction>(other.length()))
		{
			std::copy(other.begin(), other.end(), _instructions.begin());
		}

		Bytecode& Bytecode::operator=(const Bytecode& other)
		{
			Bytecode temp(other);
			swap(temp);

			return *this;
		}

		void Bytecode::swap(Bytecode& other) noexcept
		{
			std::swap(_instructions, other._instructions);
		}

		size_t Bytecode::length() const
		{
			return _instructions.size();
		}

		const Instruction& Bytecode::operator[](size_t index) const
		{
			if (index >= length())
				throw InstructionsOverException("The instruction with the " + std::to_string(index) + " index was not found");

			return _instructions[index];
		}

		const Instruction* Bytecode::begin() const noexcept
		{
			return _instructions.data();
		}

		const Instruction* Bytecode::end() const noexcept
		{
			return _instructions.data() + length();
		}
	}
}