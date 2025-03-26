#pragma once

#include <BVM/Object/Object.h>
#include <BVM/Object/CodeObject.h>

namespace BVM
{
	namespace Object
	{
		class Function : public IObject
		{
		public:
			explicit Function(std::shared_ptr<CodeObject> codeObj);

			// Overridden IObject methods
			std::shared_ptr<IObject> call() const override;

			std::string typeName() const override;
			bool isType(const std::string& type) const override;
			std::shared_ptr<IObject> clone() const override;
			std::size_t hash() const override;
			std::string toString() const override;

		private:
			std::shared_ptr<CodeObject> _codeObj;
		};
	}
}