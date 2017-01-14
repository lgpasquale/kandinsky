#include <Kandinsky/expressions/SquareRootExpression.hpp>
#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/DivisionExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr SquareRootExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(0.5 / sqrt(m_arg) * m_arg->derivative(variable));
    }
}

