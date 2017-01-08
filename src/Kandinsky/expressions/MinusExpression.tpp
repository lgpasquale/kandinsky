#ifndef KANDINSKY_MINUSEXPRESSION_TPP_
#define KANDINSKY_MINUSEXPRESSION_TPP_

#include <Kandinsky/expressions/MinusExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr MinusExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(- m_arg->derivative(variable));
    }
}

#endif

