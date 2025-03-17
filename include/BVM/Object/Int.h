#include <memory>

#include <BVM/Object/Object.h>

namespace BVM 
{
	namespace Object
	{
		class Int : IObject
		{
		public:
			explicit Int(float value) : _value(value) {}

			int64_t getValue();

			// Binary operations
			std::shared_ptr<IObject> add(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> subtract(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> multiply(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> divide(const std::shared_ptr<IObject>& other) const override;
		private:
			int64_t _value;
		};
	}
}