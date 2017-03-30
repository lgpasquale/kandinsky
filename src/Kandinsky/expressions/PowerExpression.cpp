#include <Kandinsky/expressions/PowerExpression.hpp>
#include <Kandinsky/expressions/NaturalLogarithmExpression.hpp>
#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/DivisionExpression.hpp>
#include <Kandinsky/expressions/AdditionExpression.hpp>
#include <Kandinsky/expressions/SubtractionExpression.hpp>
#include <Kandinsky/expressions/IfThenElseExpression.hpp>
#include <Kandinsky/expressions/comparison/NotEqualExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr PowerExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(ifThenElse(m_arg2->derivative(variable) != 0,
                pow(m_arg1, m_arg2) * (
                m_arg2->derivative(variable) * log(m_arg1) +
                m_arg2 * m_arg1->derivative(variable) / m_arg1),
                m_arg2 * m_arg1->derivative(variable) * pow(m_arg1, m_arg2 - 1)));
    }
}

