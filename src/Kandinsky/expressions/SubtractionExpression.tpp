#ifndef KANDINSKY_SUBTRACTIONEXPRESSION_TPP_
#define KANDINSKY_SUBTRACTIONEXPRESSION_TPP_

#include <Kandinsky/expressions/SubtractionExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr SubtractionExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(m_arg1->derivative(variable) - m_arg2->derivative(variable));
    }
}

#endif

