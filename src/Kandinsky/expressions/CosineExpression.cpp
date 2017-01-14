#include <Kandinsky/expressions/CosineExpression.hpp>
#include <Kandinsky/expressions/SineExpression.hpp>
#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/MinusExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr CosineExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(- sin(m_arg) * m_arg->derivative(variable));
    }
}

