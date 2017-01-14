#include <Kandinsky/expressions/SineExpression.hpp>
#include <Kandinsky/expressions/CosineExpression.hpp>
#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr SineExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(cos(m_arg) * m_arg->derivative(variable));
    }
}

