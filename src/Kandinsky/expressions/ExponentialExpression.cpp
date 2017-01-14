#include <Kandinsky/expressions/ExponentialExpression.hpp>
#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr ExponentialExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(exp(m_arg) * m_arg->derivative(variable));
    }
}

