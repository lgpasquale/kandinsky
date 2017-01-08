#ifndef KANDINSKY_NATURALLOGARITHMEXPRESSION_TPP_
#define KANDINSKY_NATURALLOGARITHMEXPRESSION_TPP_

#include <Kandinsky/expressions/NaturalLogarithmExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr NaturalLogarithmExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(1 / m_arg * m_arg->derivative(variable));
    }
}

#endif

