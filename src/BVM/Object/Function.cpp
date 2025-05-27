#include <BVM/Object/Function.h>
#include <BVM/Core/Exceptions.h>

namespace BVM
{
	namespace Object
	{
		Function::Function(std::shared_ptr<CodeObject> codeObj)
			: _codeObj(std::move(codeObj))
		{
			if (!_codeObj) {
				throw Core::NullReferenceException("Function cannot be constructed with null CodeObject");
			}
		}

		std::shared_ptr<IObject> Function::call() const
		{
			return _codeObj;
		}

		std::string Function::typeName() const
		{
			return "Function";
		}

		bool Function::isType(const std::string& type) const
		{
			return type == "Function";
		}

		std::shared_ptr<IObject> Function::clone() const
		{
			return std::make_shared<Function>(_codeObj);
		}

		size_t Function::hash() const
		{
			// Combine the hash of the type name with the hash of the code object
			size_t seed = (size_t)0;
			std::hash<std::string> stringHasher;
			std::hash<std::shared_ptr<CodeObject>> ptrHasher;

			seed ^= stringHasher(typeName()) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			seed ^= ptrHasher(_codeObj) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

			return seed;
		}

		std::string Function::toString() const
		{
			return "Function(" + _codeObj->toString() + ")";
		}
	}
}