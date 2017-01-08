#ifndef KANDINSKY_POWEREXPRESSION_TPP_
#define KANDINSKY_POWEREXPRESSION_TPP_

#include <Kandinsky/expressions/PowerExpression.hpp>
#include <Kandinsky/expressions/NaturalLogarithmExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr PowerExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(pow(m_arg1, m_arg2) * (
                m_arg2->derivative(variable) * log(m_arg1) +
                m_arg2 * m_arg1->derivative(variable) / m_arg1));
    }
}

#endif

