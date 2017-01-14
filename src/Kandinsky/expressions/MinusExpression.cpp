#include <Kandinsky/expressions/MinusExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr MinusExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(- m_arg->derivative(variable));
    }
}

