#ifndef KANDINSKY_BINARYEXPRESSION_HPP_
#define KANDINSKY_BINARYEXPRESSION_HPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/ExpressionTraits.hpp>

namespace Kandinsky
{
    class BinaryExpression : public BaseExpression
    {
    public:
        BinaryExpression(BaseExpressionPtr arg1, BaseExpressionPtr arg2)
            : m_arg1(arg1), m_arg2(arg2) {}

        virtual void fillVariableSet(std::set<Variable>& variableSet, const BaseExpressionPtr& /*thisSharedPtr*/) const
        {
            m_arg1->fillVariableSet(variableSet, m_arg1);
            m_arg2->fillVariableSet(variableSet, m_arg2);
        }

    protected:
        BaseExpressionPtr m_arg1;
        BaseExpressionPtr m_arg2;
    };
}

#endif

