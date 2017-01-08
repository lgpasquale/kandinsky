#ifndef KANDINSKY_ABSEXPRESSION_TPP_
#define KANDINSKY_ABSEXPRESSION_TPP_

#include <Kandinsky/expressions/AbsExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    BaseExpressionPtr AbsExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return BaseExpression::makePtr(sign(m_arg) * m_arg->derivative(variable));
    }
}

#endif

