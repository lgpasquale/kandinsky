#include <Kandinsky/expressions/SubtractionExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr SubtractionExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(m_arg1->derivative(variable) - m_arg2->derivative(variable));
    }
}

