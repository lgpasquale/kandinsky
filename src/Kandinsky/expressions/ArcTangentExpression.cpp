#include <Kandinsky/expressions/ArcTangentExpression.hpp>
#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/DivisionExpression.hpp>
#include <Kandinsky/expressions/AdditionExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr ArcTangentExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(m_arg->derivative(variable) / (1 + m_arg * m_arg));
    }
}

