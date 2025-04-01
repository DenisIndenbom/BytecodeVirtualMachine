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
		print(1 + 2)
		
		def f(a,b):
			print(a,b)

		print(f(1, 2))
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
		BVM::Core::Instruction(BVM::Core::InstructionType::HALT, 0) // Stop execution
	};

	std::vector<std::shared_ptr<BVM::Object::IObject>> constants;

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
	
	// Create CodeObject for function
	auto funcCodeObj = std::make_shared<BVM::Object::CodeObject>(std::move(bytecodeFunc), std::move(funcConstants), 0, 2);

	// Push function CodeObject to constants
	constants.push_back(funcCodeObj);

	// Create VM instance with CodeObject containing bytecode and constants
	BVM::Core::VM vm(std::make_shared<BVM::Object::CodeObject>(std::move(bytecode), std::move(constants), 1));

	vm.run();

	return 0;
}
