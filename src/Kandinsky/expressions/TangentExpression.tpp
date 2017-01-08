#ifndef KANDINSKY_TANGENTEXPRESSION_TPP_
#define KANDINSKY_TANGENTEXPRESSION_TPP_

#include <Kandinsky/expressions/TangentExpression.hpp>
#include <Kandinsky/expressions/CosineExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr TangentExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(m_arg->derivative(variable) / cos(m_arg) / cos(m_arg));
    }
}

#endif

