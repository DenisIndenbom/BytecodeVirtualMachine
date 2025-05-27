#include <BVM/Object/Object.h>
#include <BVM/Core/Exceptions.h>

namespace BVM
{
	namespace Object
	{
		// Binary operations
		std::shared_ptr<IObject> IObject::add(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'add' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::subtract(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'subtract' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::multiply(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'multiply' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::divide(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'divide' not supported for type '" + typeName() + "'");
		}

		// Comparison operations
		std::shared_ptr<IObject> IObject::equal(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'equal' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::notEqual(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'notEqual' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::greater(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'greater' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::greaterOrEqual(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'greaterOrEqual' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::less(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'less' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::lessOrEqual(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'lessOrEqual' not supported for type '" + typeName() + "'");
		}

		// Logical operations
		std::shared_ptr<IObject> IObject::logicalAnd(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'logicalAnd' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::logicalOr(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'logicalOr' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::logicalXor(const std::shared_ptr<IObject>& other) const
		{
			throw Core::InvalidOperationException("Operation 'logicalXor' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::logicalNot() const
		{
			throw Core::InvalidOperationException("Operation 'logicalNot' not supported for type '" + typeName() + "'");
		}

		// Unary operations
		std::shared_ptr<IObject> IObject::negate() const
		{
			throw Core::InvalidOperationException("Operation 'negate' not supported for type '" + typeName() + "'");
		}

		std::shared_ptr<IObject> IObject::call() const
		{
			throw Core::TypeException(typeName() + " object is not callable");
		}

		// Clone and representation
		std::shared_ptr<IObject> IObject::clone() const
		{
			throw Core::MethodNotImplementedException("Clone operation not implemented for type '" + typeName() + "'");
		}

		std::size_t IObject::hash() const
		{
			throw Core::MethodNotImplementedException("Hash operation not implemented for type '" + typeName() + "'");
		}

		// Indexing and property access
		std::shared_ptr<IObject> IObject::get(uint64_t key) const
		{
			throw Core::AttributeException("'" + typeName() + "' object has no attribute '" + std::to_string(key) + "'");
		}

		void IObject::set(uint64_t key, const std::shared_ptr<IObject>& value)
		{
			throw Core::AttributeException("'" + typeName() + "' object has no attribute '" + std::to_string(key) + "'");
		}
	}
}