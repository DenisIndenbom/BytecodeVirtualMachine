#include <BVM/Object/Int.h>

#include <BVM/Core/Exceptions.h>
#include <BVM/Object/Float.h>

namespace BVM
{
	namespace Object
	{
		int64_t Int::getValue()
		{
			return _value;
		}

		std::shared_ptr<IObject> Int::add(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);

			if (otherInt)
				return std::make_shared<Int>(_value + otherInt->getValue());

			throw Core::TypeException("Cannot add Int with non-Int");
		}

		std::shared_ptr<IObject> Int::subtract(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);

			if (otherInt)
				return std::make_shared<Int>(_value - otherInt->getValue());

			throw Core::TypeException("Cannot subtract Int with non-Int");
		}

		std::shared_ptr<IObject> Int::multiply(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);

			if (otherInt)
				return std::make_shared<Int>(_value * otherInt->getValue());

			throw Core::TypeException("Cannot multiply Int with non-Int");
		}

		std::shared_ptr<IObject> Int::divide(const std::shared_ptr<IObject>& other) const
		{
			auto otherInt = std::dynamic_pointer_cast<Int>(other);

			if (otherInt)
			{
				if (otherInt->getValue() == 0)
					throw Core::ZeroDivisionException("You cannot divide by 0");

				return std::make_shared<Float>((float) _value / (float) otherInt->getValue());
			}

			throw Core::TypeException("Cannot multiply Int with non-Int");
		}
	}
}