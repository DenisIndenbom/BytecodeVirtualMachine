#include <memory>
#include <vector>
#include <type_traits>

#include <BVM/Core/Instruction.h>
#include <BVM/Core/VM.h>

#include <BVM/Object/CodeObject.h>
#include <BVM/Object/Int.h>


int main()
{
	/*
		# Test 1
		print(1 - 2)

		# Test 2
		def f(a,b):
			print(a, b)

		# Test 3
		print(f(1, 2))

		# Test 4
		PUSH 1
		JMP *
		PUSH 2
		PRINT - *
	*/

	BVM::Core::Bytecode bytecode
	{
		// Test 1
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 1),
		BVM::Core::Instruction(BVM::Core::InstructionType::SUB, 0), // Substract two objects
		BVM::Core::Instruction(BVM::Core::InstructionType::PRINT, 0),

		// Test 2
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 2), // Load the code object
		BVM::Core::Instruction(BVM::Core::InstructionType::MAKE_FUNCTION, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::STORE, 0), // Store a function into memory

		// Test 3
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 1),
		BVM::Core::Instruction(BVM::Core::InstructionType::LOAD, 0), // Load the function
		BVM::Core::Instruction(BVM::Core::InstructionType::CALL, 2), // Call the function

		// Test 4
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::JUMP, 0), // Jump to PRINT instruction (*)
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 1),
		BVM::Core::Instruction(BVM::Core::InstructionType::PRINT, 0), // PRINT constant (*)

		BVM::Core::Instruction(BVM::Core::InstructionType::HALT, 0) // Stop execution
	};

	std::vector<std::shared_ptr<BVM::Object::IObject>> constants;
	std::vector<std::string> names;

	// Create shared pointers to Int objects, not IObject directly
	constants.push_back(std::make_shared<BVM::Object::Int>(1));
	constants.push_back(std::make_shared<BVM::Object::Int>(2));

	BVM::Core::Bytecode bytecodeFunc
	{
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_ARG, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_ARG, 1),
		BVM::Core::Instruction(BVM::Core::InstructionType::MUL, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::PRINT, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_ARG, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::RETURN, 0)
	};

	// Create array of constants for function
	std::vector<std::shared_ptr<BVM::Object::IObject>> funcConstants;
	std::vector<std::string> funcNames;
	std::vector<std::size_t> funcJumpPoints = { 15 };

	// Create CodeObject for function
	auto funcCodeObj = std::make_shared<BVM::Object::CodeObject>(std::move(bytecodeFunc), std::move(funcConstants), std::move(funcNames), std::move(funcJumpPoints), 0, 2);

	// Push function CodeObject to constants
	constants.push_back(funcCodeObj);

	std::vector<std::size_t> jumpPoints = { 14 };

	// Create VM instance with CodeObject containing bytecode and constants
	BVM::Core::VM vm(std::make_shared<BVM::Object::CodeObject>(std::move(bytecode), std::move(constants), std::move(names), std::move(jumpPoints), 1));

	vm.run();

	return 0;
}
