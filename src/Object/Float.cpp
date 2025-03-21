#include <BVM/Object/Float.h>
#include <BVM/Object/Int.h>

#include <BVM/Core/Exceptions.h>


namespace BVM
{
    namespace Object
    {
        float Float::getValue() const
        {
            return _value;
        }

        std::shared_ptr<IObject> Float::add(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Float>(_value + otherFloat->_value);

            throw Core::TypeException("Cannot add Float with non-Float");
        }

        std::shared_ptr<IObject> Float::subtract(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Float>(_value - otherFloat->_value);

            throw Core::TypeException("Cannot subtract Float with non-Float");
        }

        std::shared_ptr<IObject> Float::multiply(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Float>(_value * otherFloat->_value);

            throw Core::TypeException("Cannot multiply Float with non-Float");
        }

        std::shared_ptr<IObject> Float::divide(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
            {
                if (otherFloat->_value == 0.0f)
                    throw Core::ZeroDivisionException("You cannot divide by 0");

                return std::make_shared<Float>(_value / otherFloat->_value);
            }

            throw Core::TypeException("Cannot divide Float with non-Float");
        }

        // Comparison operations
        std::shared_ptr<IObject> Float::equal(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Int>(_value == otherFloat->_value);

            throw Core::TypeException("Cannot compare Float with non-Float");
        }

        std::shared_ptr<IObject> Float::notEqual(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Int>(_value != otherFloat->_value);

            throw Core::TypeException("Cannot compare Float with non-Float");
        }

        std::shared_ptr<IObject> Float::greater(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Int>(_value > otherFloat->_value);

            throw Core::TypeException("Cannot compare Float with non-Float");
        }

        std::shared_ptr<IObject> Float::greaterOrEqual(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Int>(_value >= otherFloat->_value);

            throw Core::TypeException("Cannot compare Float with non-Float");
        }

        std::shared_ptr<IObject> Float::less(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Int>(_value < otherFloat->_value);

            throw Core::TypeException("Cannot compare Float with non-Float");
        }

        std::shared_ptr<IObject> Float::lessOrEqual(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Int>(_value <= otherFloat->_value);

            throw Core::TypeException("Cannot compare Float with non-Float");
        }

        // Logical operations
        std::shared_ptr<IObject> Float::logicalAnd(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Int>((_value != 0.0f) && (otherFloat->_value != 0.0f));

            throw Core::TypeException("Cannot perform logical AND with non-Float");
        }

        std::shared_ptr<IObject> Float::logicalOr(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Int>((_value != 0.0f) || (otherFloat->_value != 0.0f));

            throw Core::TypeException("Cannot perform logical OR with non-Float");
        }

        std::shared_ptr<IObject> Float::logicalXor(const std::shared_ptr<IObject>& other) const
        {
            auto otherFloat = std::dynamic_pointer_cast<Float>(other);
            if (otherFloat)
                return std::make_shared<Int>((_value != 0.0f) != (otherFloat->_value != 0.0f));

            throw Core::TypeException("Cannot perform logical XOR with non-Float");
        }

        std::shared_ptr<IObject> Float::logicalNot() const
        {
            return std::make_shared<Int>(_value == 0.0f);
        }

        // Unary operations
        std::shared_ptr<IObject> Float::negate() const
        {
            return std::make_shared<Float>(-_value);
        }

        // Type information and conversion
        std::string Float::typeName() const
        {
            return "Float";
        }

        bool Float::isType(const std::string& type) const
        {
            return type == "Float";
        }

        // Clone and representation
        std::shared_ptr<IObject> Float::clone() const
        {
            return std::make_shared<Float>(_value);
        }

        std::size_t Float::hash() const
        {
            return std::hash<float>{}(_value);
        }

        std::string Float::toString() const
        {
            return std::to_string(_value);
        }
    }
}