#include <Kandinsky/expressions/IfThenElseExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr IfThenElseExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(ifThenElse(m_arg1, m_arg2->derivative(variable), m_arg3->derivative(variable)));
    }
}

