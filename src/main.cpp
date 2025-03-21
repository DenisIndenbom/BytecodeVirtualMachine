#include <iostream>
#include <vector>
#include <memory>

#include <BVM/Core/VM.h>
#include <BVM/Core/Instruction.h>

#include <BVM/Object/Int.h>
#include <BVM/Object/CodeObject.h>


int main()
{
    BVM::Core::Bytecode bytecode;

    bytecode.add(BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 0));
    bytecode.add(BVM::Core::Instruction(BVM::Core::InstructionType::PUSH_CONST, 1));
    bytecode.add(BVM::Core::Instruction(BVM::Core::InstructionType::ADD, 0));
    bytecode.add(BVM::Core::Instruction(BVM::Core::InstructionType::PRINT, 0));

    std::vector<std::shared_ptr<BVM::Object::IObject>> constants;

    // Create shared pointers to Int objects, not IObject directly
    constants.push_back(std::make_shared<BVM::Object::Int>(1));
    constants.push_back(std::make_shared<BVM::Object::Int>(1));

    // Create VM instance with CodeObject containing bytecode and constants
    BVM::Core::VM vm(std::make_shared<BVM::Object::CodeObject>(bytecode, constants, 0));

    vm.run();

    return 0;
}
