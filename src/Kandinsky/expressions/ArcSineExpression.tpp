#ifndef KANDINSKY_ARCSINEEXPRESSION_TPP_
#define KANDINSKY_ARCSINEEXPRESSION_TPP_

#include <Kandinsky/expressions/ArcSineExpression.hpp>
#include <Kandinsky/expressions/SquareRootExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr ArcSineExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(m_arg->derivative(variable) / sqrt(1 - m_arg * m_arg));
    }
}

#endif

