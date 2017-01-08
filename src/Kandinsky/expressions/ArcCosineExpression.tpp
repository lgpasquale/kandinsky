#ifndef KANDINSKY_ARCCOSINEEXPRESSION_TPP_
#define KANDINSKY_ARCCOSINEEXPRESSION_TPP_

#include <Kandinsky/expressions/ArcCosineExpression.hpp>
#include <Kandinsky/expressions/SquareRootExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr ArcCosineExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(- m_arg->derivative(variable) / sqrt(1 - m_arg * m_arg));
    }
}

#endif

