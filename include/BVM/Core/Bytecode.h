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
			Bytecode();
			~Bytecode() = default;

			size_t length() const;

			void add(const Instruction& instruction);

			const Instruction& operator[](size_t index) const;
		private:
			std::vector<Instruction> _bytecode;
		};
	}
}