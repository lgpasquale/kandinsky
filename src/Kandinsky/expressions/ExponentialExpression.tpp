#ifndef KANDINSKY_EXPONENTIALEXPRESSION_TPP_
#define KANDINSKY_EXPONENTIALEXPRESSION_TPP_

#include <Kandinsky/expressions/ExponentialExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr ExponentialExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(exp(m_arg) * m_arg->derivative(variable));
    }
}

#endif

