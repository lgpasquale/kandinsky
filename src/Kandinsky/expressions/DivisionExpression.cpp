#include <Kandinsky/expressions/DivisionExpression.hpp>
#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/SubtractionExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr DivisionExpression::derivative(const VariableExpressionPtr& variable) const
    {
        BaseExpressionPtr arg2Derivative = m_arg2->derivative(variable);
        return makePtr(m_arg1->derivative(variable) / m_arg2 -
                m_arg1 * m_arg2->derivative(variable) / m_arg2 / m_arg2);
    }
}

