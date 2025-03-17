#include <exception>
#include <string>

namespace BVM
{
	namespace Core
	{
		class Exception : public std::exception
		{
		public:
			explicit Exception(const std::string& message) : _message("Error: " + message) {}
		private:
			std::string _message;
		};

		class TypeException : public Exception
		{
		public:
			explicit TypeException(const std::string& message) : Exception("Type error: " + message) {}
		};

		class ZeroDivisionException : public Exception
		{
		public:
			explicit ZeroDivisionException(const std::string& message) : Exception("Zero division error: " + message) {}
		};
	}
}