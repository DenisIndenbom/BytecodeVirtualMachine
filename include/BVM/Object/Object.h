#pragma once

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

			// Compare operations
			virtual std::shared_ptr<IObject> equal(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> notEqual(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> greater(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> greaterOrEqual(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> less(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> lessOrEqual(const std::shared_ptr<IObject>& other) const = 0;

			// Logical (TODO: Come up with new names for locial functions)
			virtual std::shared_ptr<IObject> l_and(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> l_or(const std::shared_ptr<IObject>& other) const = 0;
			virtual std::shared_ptr<IObject> l_not(const std::shared_ptr<IObject>& other) const = 0;

		};
	}
}