#pragma once

#include <memory>

#include <BVM/Core/Instruction.h>

namespace BVM
{
	namespace Core
	{
		class Bytecode
		{
		public:
			// Constructors
			Bytecode() = default;
			Bytecode(std::unique_ptr<Instruction[]>& instructions, size_t length);
			Bytecode(const std::initializer_list<Instruction>& instrucions);

			// Deconstructor 
			~Bytecode() = default;

			// Copy constructor
			Bytecode(const Bytecode& other);

			size_t length() const;

			const Instruction& operator[](size_t index) const;
		private:
			std::unique_ptr<Instruction[]> _instructions;
			size_t _length;
		};
	}
}