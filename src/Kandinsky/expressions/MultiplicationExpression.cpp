#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/AdditionExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr MultiplicationExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(m_arg1->derivative(variable) * m_arg2 +
                m_arg1 * m_arg2->derivative(variable));
    }
}

