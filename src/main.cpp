#include <memory>
#include <vector>
#include <type_traits>

#include <BVM/Core/Instruction.h>
#include <BVM/Core/VM.h>

#include <BVM/Object/CodeObject.h>
#include <BVM/Object/Function.h>
#include <BVM/Object/Int.h>


int main()
{
	BVM::Core::Bytecode bytecode
	{
		// Test 1
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 1),
		BVM::Core::Instruction(BVM::Core::InstructionType::SUB, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::PRINT, 0),

		// Test 2
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 1),
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 2),
		BVM::Core::Instruction(BVM::Core::InstructionType::CALL, 2),
		BVM::Core::Instruction(BVM::Core::InstructionType::HALT, 0)
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

	// Create function
	auto function = std::make_shared<BVM::Object::Function>(funcCodeObj);

	// Push function to constants
	constants.push_back(function);

	// Create VM instance with CodeObject containing bytecode and constants
	BVM::Core::VM vm(std::make_shared<BVM::Object::CodeObject>(std::move(bytecode), std::move(constants), 0));

	vm.run();

	return 0;
}
