#pragma once

#include <vector>
#include <memory>

#include <BVM/Core/Bytecode.h>
#include <BVM/Object/Object.h>

namespace BVM
{
	namespace Object
	{
		class CodeObject : public IObject
		{
		public:
			CodeObject(const Core::Bytecode& bytecode, const std::vector<std::shared_ptr<IObject>>& constants, size_t localsNum);

			// Getters
			const Core::Bytecode& getBytecode() const;
			const Core::Instruction& getInstruction(size_t index) const;
			const std::shared_ptr<IObject>& getConstant(size_t index) const;
			size_t getLocalsNum() const;

			// Implement all pure virtual functions from IObject
			std::shared_ptr<IObject> add(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> subtract(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> multiply(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> divide(const std::shared_ptr<IObject>& other) const override;

			std::shared_ptr<IObject> equal(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> notEqual(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> greater(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> greaterOrEqual(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> less(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> lessOrEqual(const std::shared_ptr<IObject>& other) const override;

			std::shared_ptr<IObject> logicalAnd(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> logicalOr(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> logicalXor(const std::shared_ptr<IObject>& other) const override;
			std::shared_ptr<IObject> logicalNot() const override;

			std::shared_ptr<IObject> negate() const override;

			// Type information
			std::shared_ptr<IObject> clone() const override;
			std::size_t hash() const override;

			std::string typeName() const override;

			bool isType(const std::string& type) const override;
			std::string toString() const override;

		private:
			Core::Bytecode _bytecode;
			std::vector<std::shared_ptr<IObject>> _constants;
			size_t _localsNum;
		};
	}
}
