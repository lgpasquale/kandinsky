#ifndef KANDINSKY_ARCTANGENTEXPRESSION_TPP_
#define KANDINSKY_ARCTANGENTEXPRESSION_TPP_

#include <Kandinsky/expressions/ArcTangentExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr ArcTangentExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(m_arg->derivative(variable) / (1 + m_arg * m_arg));
    }
}

#endif

