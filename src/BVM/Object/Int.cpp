#include <BVM/Object/Int.h>
#include <BVM/Core/Exceptions.h>
#include <BVM/Object/Float.h>
#include <BVM/Object/Bool.h>

namespace BVM
{
	namespace Object
	{
		int64_t Int::getValue() const
		{
			return _value;
		}

		std::shared_ptr<IObject> Int::add(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Int>(_value + otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Float>(_value + otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Int>(_value + otherBool->getValue());
			}

			throw Core::TypeException("Cannot add Int with non-Int, non-Float, or non-Bool");
		}

		std::shared_ptr<IObject> Int::subtract(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Int>(_value - otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Float>(_value - otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Int>(_value - otherBool->getValue());
			}

			throw Core::TypeException("Cannot subtract Int with non-Int, non-Float, or non-Bool");
		}

		std::shared_ptr<IObject> Int::multiply(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Int>(_value * otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Float>(_value * otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Int>(_value * otherBool->getValue());
			}

			throw Core::TypeException("Cannot multiply Int with non-Int, non-Float, or non-Bool");
		}

		std::shared_ptr<IObject> Int::divide(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				if (otherInt->getValue() == 0) {
					throw Core::ZeroDivisionException("You cannot divide by 0");
				}

				return std::make_shared<Float>((float)_value / (float)otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				if (otherFloat->getValue() == 0.0f) {
					throw Core::ZeroDivisionException("You cannot divide by 0");
				}

				return std::make_shared<Float>((float)_value / (float)otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				if (otherBool->getValue() == false) {
					throw Core::ZeroDivisionException("You cannot divide by 0 (false)");
				}

				return std::make_shared<Float>((float)_value / (float)otherBool->getValue());
			}

			throw Core::TypeException("Cannot divide Int with non-Int, non-Float, or non-Bool");
		}

		// Comparison operations
		std::shared_ptr<IObject> Int::equal(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Bool>(_value == otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Bool>(_value == otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Bool>(_value == (int)otherBool->getValue());
			}

			throw Core::TypeException("Cannot compare Int with non-Int, non-Float, or non-Bool");
		}

		std::shared_ptr<IObject> Int::notEqual(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Bool>(_value != otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Bool>(_value != otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Bool>(_value != (int)otherBool->getValue());
			}

			throw Core::TypeException("Cannot compare Int with non-Int, non-Float, or non-Bool");
		}

		std::shared_ptr<IObject> Int::greater(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Bool>(_value > otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Bool>(_value > otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Bool>(_value > (int)otherBool->getValue());
			}

			throw Core::TypeException("Cannot compare Int with non-Int, non-Float, or non-Bool");
		}

		std::shared_ptr<IObject> Int::greaterOrEqual(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Bool>(_value >= otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Bool>(_value >= otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Bool>(_value >= (int)otherBool->getValue());
			}

			throw Core::TypeException("Cannot compare Int with non-Int, non-Float, or non-Bool");
		}

		std::shared_ptr<IObject> Int::less(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Bool>(_value < otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Bool>(_value < otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Bool>(_value < (int)otherBool->getValue());
			}

			throw Core::TypeException("Cannot compare Int with non-Int, non-Float, or non-Bool");
		}

		std::shared_ptr<IObject> Int::lessOrEqual(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Bool>(_value <= otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Bool>(_value <= otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Bool>(_value <= (int)otherBool->getValue());
			}

			throw Core::TypeException("Cannot compare Int with non-Int, non-Float, or non-Bool");
		}

		// Logical operations
		std::shared_ptr<IObject> Int::logicalAnd(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Int>(_value && otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Int>(_value && otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Int>(_value && otherBool->getValue());
			}

			throw Core::TypeException("Cannot perform logical AND with non-Int, non-Float, or non-Bool");
		}

		std::shared_ptr<IObject> Int::logicalOr(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Int>(_value || otherInt->getValue());
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Int>(_value || otherFloat->getValue());
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Int>(_value || otherBool->getValue());
			}

			throw Core::TypeException("Cannot perform logical OR with non-Int, non-Float, or non-Bool");
		}

		std::shared_ptr<IObject> Int::logicalXor(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);
			if (otherInt) {
				return std::make_shared<Int>((_value != 0) != (otherInt->getValue() != 0));
			}

			auto otherFloat = std::dynamic_pointer_cast<Float>(other);
			if (otherFloat) {
				return std::make_shared<Int>((_value != 0) != (otherFloat->getValue() != 0.0f));
			}

			auto otherBool = std::dynamic_pointer_cast<Bool>(other);
			if (otherBool) {
				return std::make_shared<Int>((_value != 0) != (otherBool->getValue() != 0));
			}

			throw Core::TypeException("Cannot perform logical XOR with non-Int, non-Float, or non-Bool");
		}

		std::shared_ptr<IObject> Int::logicalNot() const
		{
			return std::make_shared<Int>(_value == 0);
		}

		// Unary operations
		std::shared_ptr<IObject> Int::negate() const
		{
			return std::make_shared<Int>(-_value);
		}

		// Type information and conversion
		std::string Int::typeName() const
		{
			return "Int";
		}

		bool Int::isType(const std::string& type) const
		{
			return type == "Int";
		}

		// Clone and representation
		std::shared_ptr<IObject> Int::clone() const
		{
			return std::make_shared<Int>(_value);
		}

		std::size_t Int::hash() const
		{
			return std::hash<int64_t>{}(_value);
		}

		std::string Int::toString() const
		{
			return std::to_string(_value);
		}
	}
}