#include <vector>
#include <memory>

#include <BVM/Core/VM.h>
#include <BVM/Core/Instruction.h>

#include <BVM/Object/Int.h>
#include <BVM/Object/CodeObject.h>
#include <BVM/Object/Function.h>


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
		BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 0),
		BVM::Core::Instruction(BVM::Core::InstructionType::RETURN, 0)
	};
	
	auto funcCodeObj = std::make_shared<BVM::Object::CodeObject>(bytecodeFunc, constants, 0, 2);
	
	auto function = std::make_shared<BVM::Object::Function>(funcCodeObj);

	constants.push_back(function);

	// Create VM instance with CodeObject containing bytecode and constants
	BVM::Core::VM vm(std::make_shared<BVM::Object::CodeObject>(bytecode, constants, 0));

	vm.run();

	return 0;
}
