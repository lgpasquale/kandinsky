#ifndef KANDINSKY_BINARYEXPRESSION_HPP_
#define KANDINSKY_BINARYEXPRESSION_HPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/ExpressionTraits.hpp>

namespace Kandinsky
{
    class BinaryExpression : public BaseExpression
    {
    public:
        BinaryExpression(const BaseExpressionPtr& arg1, const BaseExpressionPtr& arg2)
            : m_arg1(arg1), m_arg2(arg2) {}

        virtual void fillVariableSet(std::set<Variable, VariableLessThanComparator>& variableSet, const BaseExpressionPtr& /*thisSharedPtr*/) const
        {
            m_arg1->fillVariableSet(variableSet, m_arg1);
            m_arg2->fillVariableSet(variableSet, m_arg2);
        }

        virtual bool isConstant() const
        {
            return m_arg1->isConstant() && m_arg2->isConstant();
        }

        virtual size_t sizeOfInternalNodes() const
        {
            return sizeof(*this) + m_arg1->sizeOfInternalNodes()
                + m_arg2->sizeOfInternalNodes();
        }

        virtual size_t numberOfInternalNodes() const
        {
            return 1 + m_arg1->numberOfInternalNodes()
                + m_arg2->numberOfInternalNodes();
        }

        virtual size_t numberOfConstants() const
        {
            return m_arg1->numberOfConstants() + m_arg2->numberOfConstants();
        }

    protected:
        BaseExpressionPtr m_arg1;
        BaseExpressionPtr m_arg2;
    };
}

#endif
