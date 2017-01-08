#ifndef KANDINSKY_MULTIPLICATIONEXPRESSION_TPP_
#define KANDINSKY_MULTIPLICATIONEXPRESSION_TPP_

#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/AdditionExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr MultiplicationExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(m_arg1->derivative(variable) * m_arg2 +
                m_arg1 * m_arg2->derivative(variable));
    }
}

#endif

