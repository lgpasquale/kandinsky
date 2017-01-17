#ifndef KANDINSKY_TERNARYEXPRESSION_HPP_
#define KANDINSKY_TERNARYEXPRESSION_HPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/ExpressionTraits.hpp>

namespace Kandinsky
{
    class TernaryExpression : public BaseExpression
    {
    public:
        TernaryExpression(const BaseExpressionPtr& arg1, const BaseExpressionPtr& arg2, const BaseExpressionPtr& arg3)
            : m_arg1(arg1), m_arg2(arg2), m_arg3(arg3) {}

        virtual void fillVariableSet(std::set<Variable, VariableLessThanComparator>& variableSet, const BaseExpressionPtr& /*thisSharedPtr*/) const
        {
            m_arg1->fillVariableSet(variableSet, m_arg1);
            m_arg2->fillVariableSet(variableSet, m_arg2);
            m_arg3->fillVariableSet(variableSet, m_arg3);
        }

    protected:
        BaseExpressionPtr m_arg1;
        BaseExpressionPtr m_arg2;
        BaseExpressionPtr m_arg3;
    };
}

#endif

