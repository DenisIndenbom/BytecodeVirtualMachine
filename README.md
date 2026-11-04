# BytecodeVirtualMachine

A stack-based bytecode virtual machine written in C++20, inspired by CPython's architecture.

## About

An educational project aimed at understanding how an interpreter works from the inside -
from a bytecode instruction to function calls and stack management. The VM executes
bytecode in the "opcode + argument" format, supports dynamic typing (arithmetic across
`Int`, `Float`, `Bool`), and implements function calls via a frame chain.

## Features

- **Object types**: `Int`, `Float`, `Bool`, `CodeObject`, `Function` via the `IObject` hierarchy
- **Arithmetic & comparison**: `+`, `-`, `*`, `/`, `==`, `!=`, `<`, `>`, `<=`, `>=`
- **Logical operations**: `AND`, `OR`, `XOR`, `NOT`
- **Stack**: `PUSH_CONST`, `PUSH_ARG`, `POP`, `DUP`, `SWAP`, `ROT`, `OVER`
- **Control flow**: `JUMP`, `JUMP_IF_TRUE`, `JUMP_IF_FALSE`, `CALL`, `RETURN`, `HALT`
- **Memory**: `LOAD`, `STORE`, `LOAD_GLOBAL`, `STORE_GLOBAL`
- **Functions**: `MAKE_FUNCTION`, frames with operand stack, locals, and arguments
- **Debugging**: `PRINT` and descriptive exceptions for every VM error

## Architecture

Key components:

- **`IObject`** - abstract base class of all VM objects. All operations
  (arithmetic, comparison, logic) are virtual; by default they throw
  `InvalidOperationException`, and derived classes override the ones they support.
- **`Bytecode`** - a vector of `{InstructionType, uint8_t arg}` instructions.
- **`Frame`** - execution frame: operand stack, locals, arguments,
  instruction pointer, and a pointer to the previous frame.
- **`CodeObject`** - "compiled" code: bytecode, constants, names, jump points,
  number of locals and arguments.
- **`VM`** - a `switch`-based execution loop and the frame chain manager.

## C++ features used

`std::shared_ptr` (RAII for VM objects), virtual methods and `override`,
`dynamic_pointer_cast`, `enum class`, Rule of Five for `Bytecode`
(copy, move, destructor, `swap`), `[[nodiscard]]`, `std::move`, `noexcept`,
`initializer_list`, `std::make_shared`.

## Build

Requirements: CMake >= 3.12, a compiler with C++20 support.

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/BytecodeVirtualMachine
```

## Bytecode example

Program `print(1 - 2)`:

```cpp
BVM::Core::Bytecode bytecode {
    { InstructionType::PUSH_CONST, 0 }, // 1
    { InstructionType::PUSH_CONST, 1 }, // 2
    { InstructionType::SUB, 0 },        // -1
    { InstructionType::PRINT, 0 },      // print
    { InstructionType::HALT, 0 }        // stop
};
```

## Limitations & roadmap

- Instruction argument is `uint8_t`, limiting code to 256 constants and locals
- No unit tests (planned: Google Test / Catch2)
- No parser: bytecode is written by hand
- `switch` - based dispatch (planned: compare against computed goto)

## License

MIT License - see `LICENSE.txt`.
