#include <BVM/Object/Int.h>

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
			Int otherInt = std::dynamic_pointer_cast<Int>(other);

			if (otherInt)
				return std::make_shared<Int>(_value + otherInt->getValue());

			throw std::runtime_error("Type mismatch: Cannot add Int with non-Int");
		}

		std::shared_ptr<IObject> Int::subtract(const std::shared_ptr<IObject>& other) const
		{
			Int otherInt = std::dynamic_pointer_cast<Int>(other);

			if (otherInt)
				return std::make_shared<Int>(value - otherInt->getValue());

			throw std::runtime_error("Type mismatch: Cannot subtract Int with non-Int");
		}

		std::shared_ptr<IObject> Int::multiply(const std::shared_ptr<IObject>& other) const
		{
			Int otherInt = std::dynamic_pointer_cast<Int>(other);

			if (otherInt)
				return std::make_shared<Int>(value * otherInt->getValue());

			throw std::runtime_error("Type mismatch: Cannot multiply Int with non-Int");
		}

		std::shared_ptr<IObject> Int::divide(const std::shared_ptr<IObject>& other) const
		{
			Int otherInt = std::dynamic_pointer_cast<Int>(other);

			if (otherInt)
			{
				if (otherInt->getValue())
					throw std::runtime_error("ZeroDivisionError: You cannot divide by 0");

				return std::make_shared<Int>(value / otherInt->getValue());
			}

			throw std::runtime_error("Type mismatch: Cannot multiply Int with non-Int");
		}
	}
}