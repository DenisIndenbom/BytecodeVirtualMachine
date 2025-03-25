#pragma once

#include <exception>
#include <string>

namespace BVM
{
	namespace Core
	{
		class Exception : public std::exception
		{
		public:
			explicit Exception(const std::string& message) : _message(message) {}

			const char* what() const noexcept override
			{
				return _message.c_str();
			}

		protected:
			std::string _message;
		};

		class InstructionsOverException : public Exception
		{
		public:
			explicit InstructionsOverException(const std::string& message)
				: Exception("Instructions is Over: " + message)
			{}
		};

		class LocalsException : public Exception
		{
		public:
			explicit LocalsException(const std::string& message)
				: Exception("Locals: " + message)
			{}
		};

		class TypeException : public Exception
		{
		public:
			explicit TypeException(const std::string& message)
				: Exception("Type: " + message)
			{}
		};

		class ZeroDivisionException : public Exception
		{
		public:
			explicit ZeroDivisionException(const std::string& message)
				: Exception("Zero Division: " + message)
			{}
		};

		class InvalidBytecodeException : public Exception
		{
		public:
			explicit InvalidBytecodeException(const std::string& message)
				: Exception("Invalid Bytecode: " + message)
			{}
		};

		class StackOverflowException : public Exception
		{
		public:
			explicit StackOverflowException(const std::string& message)
				: Exception("Stack Overflow: " + message)
			{}
		};

		class StackUnderflowException : public Exception
		{
		public:
			explicit StackUnderflowException(const std::string& message)
				: Exception("Stack Underflow: " + message)
			{}
		};

		class OutOfBoundsException : public Exception
		{
		public:
			explicit OutOfBoundsException(const std::string& message)
				: Exception("Out of Bounds: " + message)
			{}
		};

		class UndefinedVariableException : public Exception
		{
		public:
			explicit UndefinedVariableException(const std::string& message)
				: Exception("Undefined Variable: " + message)
			{}
		};

		class AttributeException : public Exception
		{
		public:
			explicit AttributeException(const std::string& message)
				: Exception("Attribute Error: " + message)
			{}
		};

		class MethodNotImplementedException : public Exception
		{
		public:
			explicit MethodNotImplementedException(const std::string& message)
				: Exception("Method Not Implemented: " + message)
			{}
		};

		class InvalidOperationException : public Exception
		{
		public:
			explicit InvalidOperationException(const std::string& message)
				: Exception("Invalid Operation: " + message)
			{}
		};

		class MemoryAccessException : public Exception
		{
		public:
			explicit MemoryAccessException(const std::string& message)
				: Exception("Memory Access Violation: " + message)
			{}
		};

		class NullReferenceException : public Exception
		{
		public:
			explicit NullReferenceException(const std::string& message)
				: Exception("Null Reference: " + message)
			{}
		};
	}
}
