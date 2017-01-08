#ifndef KANDINSKY_SINEEXPRESSION_TPP_
#define KANDINSKY_SINEEXPRESSION_TPP_

#include <Kandinsky/expressions/SineExpression.hpp>
#include <Kandinsky/expressions/CosineExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr SineExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(cos(m_arg) * m_arg->derivative(variable));
    }
}

#endif

