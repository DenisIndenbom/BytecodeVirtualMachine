#pragma once

#include <vector>

#include <BVM/Core/Instruction.h>

namespace BVM
{
	namespace Core
	{
		class Bytecode
		{
		public:
			Bytecode() = default;
			Bytecode(std::vector<Instruction>&& instructions);
			Bytecode(const std::initializer_list<Instruction>& instrucions);
			~Bytecode() = default;

			// Copy
			Bytecode(const Bytecode& other);
			Bytecode& operator=(const Bytecode& other);

			// Move
			Bytecode(Bytecode&&) noexcept = default;
			Bytecode& operator=(Bytecode&&) noexcept = default;

			// Swap
			void swap(Bytecode& other) noexcept;

			size_t length() const;

			const Instruction& operator[](size_t index) const;

			// Iterators
			const Instruction* begin() const noexcept;
			const Instruction* end() const noexcept;
		private:
			std::vector<Instruction> _instructions;
		};
	}
}