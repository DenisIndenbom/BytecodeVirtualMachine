#pragma once

#include <memory>
#include <string>
#include <cstdint>

namespace BVM
{
	namespace Object
	{
		class IObject
		{
		public:
			virtual ~IObject() = default;

			// Binary operations
			virtual std::shared_ptr<IObject> add(const std::shared_ptr<IObject>& other) const;
			virtual std::shared_ptr<IObject> subtract(const std::shared_ptr<IObject>& other) const;
			virtual std::shared_ptr<IObject> multiply(const std::shared_ptr<IObject>& other) const;
			virtual std::shared_ptr<IObject> divide(const std::shared_ptr<IObject>& other) const;

			// Comparison operations
			virtual std::shared_ptr<IObject> equal(const std::shared_ptr<IObject>& other) const;
			virtual std::shared_ptr<IObject> notEqual(const std::shared_ptr<IObject>& other) const;
			virtual std::shared_ptr<IObject> greater(const std::shared_ptr<IObject>& other) const;
			virtual std::shared_ptr<IObject> greaterOrEqual(const std::shared_ptr<IObject>& other) const;
			virtual std::shared_ptr<IObject> less(const std::shared_ptr<IObject>& other) const;
			virtual std::shared_ptr<IObject> lessOrEqual(const std::shared_ptr<IObject>& other) const;

			// Logical operations
			virtual std::shared_ptr<IObject> logicalAnd(const std::shared_ptr<IObject>& other) const;
			virtual std::shared_ptr<IObject> logicalOr(const std::shared_ptr<IObject>& other) const;
			virtual std::shared_ptr<IObject> logicalXor(const std::shared_ptr<IObject>& other) const;
			virtual std::shared_ptr<IObject> logicalNot() const;

			// Unary operations
			virtual std::shared_ptr<IObject> negate() const;

			// Callable objects
			virtual std::shared_ptr<IObject> call() const;

			// Type information and conversion (pure virtual)
			virtual std::string typeName() const = 0;
			virtual bool isType(const std::string& type) const = 0;

			// Clone and representation
			virtual std::shared_ptr<IObject> clone() const;
			virtual std::size_t hash() const;
			virtual std::string toString() const = 0;

			// Indexing and property access
			virtual std::shared_ptr<IObject> get(uint64_t key) const;
			virtual void set(uint64_t key, const std::shared_ptr<IObject>& value);
		};
	}
}