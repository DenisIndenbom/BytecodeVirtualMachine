#include <BVM/Core/Bytecode.h>

#include <string>
#include <utility>

#include <BVM/Core/Exceptions.h>

namespace BVM
{
	namespace Core
	{
		Bytecode::Bytecode(std::unique_ptr<Instruction[]> instructions, size_t length) : _instructions(std::move(instructions)), _length(length) {}

		Bytecode::Bytecode(const std::initializer_list<Instruction>& instructions) : _instructions(std::make_unique<Instruction[]>(instructions.size())), _length(instructions.size())
		{
			std::copy(instructions.begin(), instructions.end(), _instructions.get());
		}

		Bytecode::Bytecode(const Bytecode& other) : _instructions(std::make_unique<Instruction[]>(other._length)), _length(other._length)
		{
			std::copy(other._instructions.get(), other._instructions.get() + other._length, _instructions.get());
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
			std::swap(_length, other._length);
		}

		size_t Bytecode::length() const
		{
			return _length;
		}

		const Instruction& Bytecode::operator[](size_t index) const
		{
			if (index >= _length)
				throw InstructionsOverException("The instruction with the " + std::to_string(index) + " index was not found");

			return _instructions[index];
		}

		const Instruction* Bytecode::begin() const noexcept
		{
			return _instructions.get();
		}

		const Instruction* Bytecode::end() const noexcept
		{
			return _instructions.get() + _length;
		}
	}
}