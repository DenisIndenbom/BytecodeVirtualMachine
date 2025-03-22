#pragma once

#include <memory>

#include <BVM/Object/Object.h>

namespace BVM
{
	namespace Object
	{
		class Bool : public IObject
		{
		public:
			explicit Bool(bool value) : _value(value) {}

			bool getValue() const;

			// Binary operations
			std::shared_ptr<IObject> add(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> subtract(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> multiply(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> divide(const std::shared_ptr<IObject>& other) const override;

			// Comparison operations
			std::shared_ptr<IObject> equal(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> notEqual(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> greater(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> greaterOrEqual(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> less(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> lessOrEqual(const std::shared_ptr<IObject>& other) const override;

			// Logical operations
			std::shared_ptr<IObject> logicalAnd(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> logicalOr(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> logicalXor(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> logicalNot() const override;

			// Unary operations
			std::shared_ptr<IObject> negate() const override;

			// Type information and conversion
			std::string typeName() const override;
			bool isType(const std::string& type) const override;

			// Clone and representation
			std::shared_ptr<IObject> clone() const override;
			std::size_t hash() const override;
			std::string toString() const override;

		private:
			bool _value;
		};
	}
}
