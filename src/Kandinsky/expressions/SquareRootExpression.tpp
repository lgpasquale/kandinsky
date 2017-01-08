#ifndef KANDINSKY_SQUAREROOTEXPRESSION_TPP_
#define KANDINSKY_SQUAREROOTEXPRESSION_TPP_

#include <Kandinsky/expressions/SquareRootExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr SquareRootExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(0.5 / sqrt(m_arg) * m_arg->derivative(variable));
    }
}

#endif

