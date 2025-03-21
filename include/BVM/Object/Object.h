#pragma once

#include <memory>
#include <string>

namespace BVM
{
	namespace Object
	{
		class IObject
		{
		public:
			virtual ~IObject() = default;

			// Binary operations
			virtual std::shared_ptr<IObject> add(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> subtract(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> multiply(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> divide(const std::shared_ptr<IObject>& other) const = 0;

			// Comparison operations
			virtual std::shared_ptr<IObject> equal(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> notEqual(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> greater(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> greaterOrEqual(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> less(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> lessOrEqual(const std::shared_ptr<IObject>& other) const = 0;

			// Logical operations
			virtual std::shared_ptr<IObject> logicalAnd(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> logicalOr(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> logicalXor(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> logicalNot() const = 0;

			// Unary operations
			virtual std::shared_ptr<IObject> negate() const = 0;

			// Type information and conversion
			virtual std::string typeName() const = 0;
			virtual bool isType(const std::string& type) const = 0;

			// Clone and representation
			virtual std::shared_ptr<IObject> clone() const = 0;
			virtual std::size_t hash() const = 0;
			virtual std::string toString() const = 0;


			// Indexing and property access (optional, for container-like objects)
			//virtual std::shared_ptr<IObject> get(const std::shared_ptr<IObject>& key) const = 0;
			//virtual void set(const std::shared_ptr<IObject>& key, const std::shared_ptr<IObject>& value) = 0;
		};
	}
}
