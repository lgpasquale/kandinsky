#ifndef KANDINSKY_COSINEEXPRESSION_TPP_
#define KANDINSKY_COSINEEXPRESSION_TPP_

#include <Kandinsky/expressions/CosineExpression.hpp>
#include <Kandinsky/expressions/SineExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr CosineExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(- sin(m_arg) * m_arg->derivative(variable));
    }
}

#endif

