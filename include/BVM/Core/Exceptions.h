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

			// Override what() to return the error message
			const char* what() const noexcept override
			{
				return _message.c_str();
			}

		protected:
			std::string _message; // Protected to allow access in derived classes
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
	}
}