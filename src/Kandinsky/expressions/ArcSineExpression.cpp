#include <Kandinsky/expressions/ArcSineExpression.hpp>
#include <Kandinsky/expressions/SquareRootExpression.hpp>
#include <Kandinsky/expressions/MultiplicationExpression.hpp>
#include <Kandinsky/expressions/DivisionExpression.hpp>
#include <Kandinsky/expressions/SubtractionExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr ArcSineExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(m_arg->derivative(variable) / sqrt(1 - m_arg * m_arg));
    }
}

