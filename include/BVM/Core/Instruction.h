#pragma once

namespace BVM
{
	namespace Core
	{
		// All possible bytecode instructions
		enum class InstructionType
		{
			// Arithmetic
			ADD,        // Pop the top two values, add them, and push the result onto the stack
			SUB,        // Pop the top two values, subtract the second from the first, and push the result
			MUL,        // Pop the top two values, multiply them, and push the result onto the stack
			DIV,        // Pop the top two values, divide the first by the second, and push the result
			MOD,		// Pop the top two values, mod the first by the second, and push the result
			IDIV,		// Pop the top two values, divide integers the first by the second, and push the result

			// Control Flow
			JUMP,       // Jump to a specific instruction
			JUMP_IF_TRUE,  // Jump if the top of the stack is true
			JUMP_IF_FALSE, // Jump if the top of the stack is false
			CALL,       // Call a function
			RETURN,     // Return from a function

			// Stack Manipulation
			PUSH_CONST, // Push a constant value (e.g., number, string, object) onto the stack
			POP,        // Remove and discard the top value from the stack
			DUP,        // Duplicate the top element of the stack
			SWAP,       // Swap the top two elements of the stack
			ROT,        // Rotate the top three elements of the stack
			OVER,       // Copy the second element from the top of the stack

			// Memory/Storage
			LOAD,       // Load a value from memory
			STORE,      // Store the top of the stack into memory
			LOAD_GLOBAL, // Load a global value
			STORE_GLOBAL, // Store the top of the stack into a global variable

			// Object Manipulation
			NEW_OBJECT, // Create a new object
			GET_ATTR,  // Get a attribute from an object
			SET_ATTR,  // Set a attribute on an object

			// Comparison
			EQ,         // Check if two objects are equal
			NEQ,        // Check if two objects are not equal
			LT,         // Check if the first object is less than the second
			GT,         // Check if the first object is greater than the second
			LTE,        // Check if the first object is less than or equal to the second
			GTE,        // Check if the first object is greater than or equal to the second

			// Logical
			AND,        // Logical AND
			OR,         // Logical OR
			NOT,        // Logical NOT

			// Type Conversion
			TO_INT,     // Convert the top of the stack to an integer
			TO_FLOAT,   // Convert the top of the stack to a float
			TO_STRING,  // Convert the top of the stack to a string

			// Debugging/Utility
			PRINT,      // Print the top of the stack
			HALT        // Stop the execution of the VM
		};

		struct Instruction
		{
			InstructionType type;
			uint8_t arg;

			Instruction() = default;
			Instruction(InstructionType type, uint8_t arg) : type(type), arg(arg) {}
			~Instruction() = default;
		};
	}
}