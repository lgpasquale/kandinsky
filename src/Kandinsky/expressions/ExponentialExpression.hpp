#ifndef KANDINSKY_EXPONENTIALEXPRESSION_HPP_
#define KANDINSKY_EXPONENTIALEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    template <class ExpressionType>
    class ExponentialExpression : public UnaryExpression<ExpressionType>
    {
    public:
        ExponentialExpression(ExpressionType expression)
            : UnaryExpression<ExpressionType>(expression) {}

        double evaluate() const
        {
            return std::exp(this->m_expression.evaluate());
        }
    };

    template <class ExpressionType>
    ExponentialExpression<ExpressionType>
    exp(ExpressionType expression)
    {
        return ExponentialExpression<ExpressionType>(expression);
    }
}

#endif

