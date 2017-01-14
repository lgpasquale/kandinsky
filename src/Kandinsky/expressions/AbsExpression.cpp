#include <Kandinsky/expressions/AbsExpression.hpp>
#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

#include <cmath>

namespace Kandinsky
{
    BaseExpressionPtr AbsExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return BaseExpression::makePtr(sign(m_arg) * m_arg->derivative(variable));
    }
}

