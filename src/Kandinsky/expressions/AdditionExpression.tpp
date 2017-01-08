#ifndef KANDINSKY_ADDITIONEXPRESSION_TPP_
#define KANDINSKY_ADDITIONEXPRESSION_TPP_

#include <Kandinsky/expressions/AdditionExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr AdditionExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(m_arg1->derivative(variable) + m_arg2->derivative(variable));
    }
}

#endif

