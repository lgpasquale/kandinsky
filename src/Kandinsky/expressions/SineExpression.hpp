#ifndef KANDINSKY_SINEEXPRESSION_HPP_
#define KANDINSKY_SINEEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    template <class ExpressionType>
    class SineExpression : public UnaryExpression<ExpressionType>
    {
    public:
        SineExpression(ExpressionType expression)
            : UnaryExpression<ExpressionType>(expression) {}

        double evaluate() const
        {
            return std::sin(this->m_expression.evaluate());
        }
    };

    template <class ExpressionType>
    SineExpression<ExpressionType>
    sin(ExpressionType expression)
    {
        return SineExpression<ExpressionType>(expression);
    }
}

#endif

