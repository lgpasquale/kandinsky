#include <Kandinsky/expressions/NaturalLogarithmExpression.hpp>
#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/DivisionExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr NaturalLogarithmExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(1 / m_arg * m_arg->derivative(variable));
    }
}

