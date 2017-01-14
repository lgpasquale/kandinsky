#include <Kandinsky/expressions/TangentExpression.hpp>
#include <Kandinsky/expressions/CosineExpression.hpp>
#include <Kandinsky/expressions/DivisionExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr TangentExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(m_arg->derivative(variable) / cos(m_arg) / cos(m_arg));
    }
}

