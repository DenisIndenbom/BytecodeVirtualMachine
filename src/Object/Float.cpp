#include <BVM/Object/Float.h>

#include <BVM/Core/Exceptions.h>

namespace BVM
{
	namespace Object
	{
		float Float::getValue()
		{
			return _value;
		}

		std::shared_ptr<IObject> Float::add(const std::shared_ptr<IObject>& other) const
		{
			auto otherFloat = std::dynamic_pointer_cast<Float>(other);

			if (otherFloat)
				return std::make_shared<Float>(_value + otherFloat->getValue());

			throw Core::TypeException("Cannot add Float with non-Float");
		}

		std::shared_ptr<IObject> Float::subtract(const std::shared_ptr<IObject>& other) const
		{
			auto otherFloat = std::dynamic_pointer_cast<Float>(other);

			if (otherFloat)
				return std::make_shared<Float>(_value - otherFloat->getValue());

			throw Core::TypeException("Cannot subtract Float with non-Float");
		}

		std::shared_ptr<IObject> Float::multiply(const std::shared_ptr<IObject>& other) const
		{
			auto otherFloat = std::dynamic_pointer_cast<Float>(other);

			if (otherFloat)
				return std::make_shared<Float>(_value * otherFloat->getValue());

			throw Core::TypeException("Cannot multiply Float with non-Float");
		}

		std::shared_ptr<IObject> Float::divide(const std::shared_ptr<IObject>& other) const
		{
			auto otherFloat = std::dynamic_pointer_cast<Float>(other);

			if (otherFloat)
			{
				if (otherFloat->getValue() == 0)
					throw Core::ZeroDivisionException("You cannot divide by 0");

				return std::make_shared<Float>(_value / otherFloat->getValue());
			}

			throw Core::TypeException("Cannot multiply Float with non-Float");
		}
	}
}