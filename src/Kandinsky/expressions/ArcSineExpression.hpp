#ifndef KANDINSKY_ARCSINEEXPRESSION_HPP_
#define KANDINSKY_ARCSINEEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    template <class ExpressionType>
    class ArcSineExpression : public UnaryExpression<ExpressionType>
    {
    public:
        ArcSineExpression(ExpressionType expression)
            : UnaryExpression<ExpressionType>(expression) {}

        double evaluate() const
        {
            return std::asin(this->m_expression.evaluate());
        }
    };

    template <class ExpressionType>
    ArcSineExpression<ExpressionType>
    asin(ExpressionType expression)
    {
        return ArcSineExpression<ExpressionType>(expression);
    }
}

#endif

