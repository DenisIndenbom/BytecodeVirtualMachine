#include <BVM/Object/Bool.h>
#include <BVM/Object/Int.h>
#include <BVM/Object/Float.h>
#include <BVM/Core/Exceptions.h>

namespace BVM
{
    namespace Object
    {
        bool Bool::getValue() const
        {
            return _value;
        }

        // Binary operations
        std::shared_ptr<IObject> Bool::add(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Int>(_value + otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Int>(_value + otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Float>(_value + otherFloat->getValue());

            throw Core::TypeException("Cannot add Bool with non-Bool, non-Int, or non-Float");
        }

        std::shared_ptr<IObject> Bool::subtract(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Int>(_value - otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Int>(_value - otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Float>(_value - otherFloat->getValue());

            throw Core::TypeException("Cannot subtract Bool with non-Bool, non-Int, or non-Float");
        }

        std::shared_ptr<IObject> Bool::multiply(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Int>(_value * otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Int>(_value * otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Float>(_value * otherFloat->getValue());

            throw Core::TypeException("Cannot multiply Bool with non-Bool, non-Int, or non-Float");
        }

        std::shared_ptr<IObject> Bool::divide(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
            {
                if (otherBool->getValue() == false)
                    throw Core::ZeroDivisionException("You cannot divide by 0 (false)");

                return std::make_shared<Float>(static_cast<float>(_value) / static_cast<float>(otherBool->getValue()));
            }

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
            {
                if (otherInt->getValue() == 0)
                    throw Core::ZeroDivisionException("You cannot divide by 0");

                return std::make_shared<Float>(static_cast<float>(_value) / static_cast<float>(otherInt->getValue()));
            }

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
            {
                if (otherFloat->getValue() == 0.0f)
                    throw Core::ZeroDivisionException("You cannot divide by 0");

                return std::make_shared<Float>(static_cast<float>(_value) / otherFloat->getValue());
            }

            throw Core::TypeException("Cannot divide Bool with non-Bool, non-Int, or non-Float");
        }

        // Comparison operations
        std::shared_ptr<IObject> Bool::equal(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Bool>(_value == otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Bool>((int)_value == otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Bool>((float)_value == otherFloat->getValue());

            throw Core::TypeException("Cannot compare Bool with non-Bool, non-Int, or non-Float");
        }

        std::shared_ptr<IObject> Bool::notEqual(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Bool>(_value != otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Bool>((int)_value != otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Bool>((float)_value != otherFloat->getValue());

            throw Core::TypeException("Cannot compare Bool with non-Bool, non-Int, or non-Float");
        }

        std::shared_ptr<IObject> Bool::greater(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Bool>(_value > otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Bool>((int)_value > otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Bool>((float)_value > otherFloat->getValue());

            throw Core::TypeException("Cannot compare Bool with non-Bool, non-Int, or non-Float");
        }

        std::shared_ptr<IObject> Bool::greaterOrEqual(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Bool>(_value >= otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Bool>((int)_value >= otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Bool>((float)_value >= otherFloat->getValue());

            throw Core::TypeException("Cannot compare Bool with non-Bool, non-Int, or non-Float");
        }

        std::shared_ptr<IObject> Bool::less(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Bool>(_value < otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Bool>((int)_value < otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Bool>((float)_value < otherFloat->getValue());

            throw Core::TypeException("Cannot compare Bool with non-Bool, non-Int, or non-Float");
        }

        std::shared_ptr<IObject> Bool::lessOrEqual(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Bool>(_value <= otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Bool>((int)_value <= otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Bool>((float)_value <= otherFloat->getValue());

            throw Core::TypeException("Cannot compare Bool with non-Bool, non-Int, or non-Float");
        }

        // Logical operations
        std::shared_ptr<IObject> Bool::logicalAnd(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Bool>(_value && otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Bool>((int)_value && otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Bool>((float)_value && otherFloat->getValue());

            throw Core::TypeException("Cannot perform logical AND with non-Bool, non-Int, or non-Float");
        }

        std::shared_ptr<IObject> Bool::logicalOr(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Bool>(_value || otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Bool>(_value || otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Bool>(_value || otherFloat->getValue());

            throw Core::TypeException("Cannot perform logical OR with non-Bool, non-Int, or non-Float");
        }

        std::shared_ptr<IObject> Bool::logicalXor(const std::shared_ptr<IObject>& other) const
        {
            auto otherBool = std::dynamic_pointer_cast<Bool>(other);
            if (otherBool)
                return std::make_shared<Bool>(_value != otherBool->getValue());

            auto otherInt = std::dynamic_pointer_cast<Int>(other);
            if (otherInt)
                return std::make_shared<Bool>((int)_value != otherInt->getValue());

            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Bool>((float)_value != otherFloat->getValue());

            throw Core::TypeException("Cannot perform logical XOR with non-Bool, non-Int, or non-Float");
        }

        std::shared_ptr<IObject> Bool::logicalNot() const
        {
            return std::make_shared<Bool>(!_value);
        }

        // Unary operations
        std::shared_ptr<IObject> Bool::negate() const
        {
            return std::make_shared<Int>(-static_cast<int>(_value));
        }

        // Type information and conversion
        std::string Bool::typeName() const
        {
            return "Bool";
        }

        bool Bool::isType(const std::string& type) const
        {
            return type == "Bool";
        }

        // Clone and representation
        std::shared_ptr<IObject> Bool::clone() const
        {
            return std::make_shared<Bool>(_value);
        }

        std::size_t Bool::hash() const
        {
            return std::hash<bool>{}(_value);
        }

        std::string Bool::toString() const
        {
            return _value ? "true" : "false";
        }
    }
}