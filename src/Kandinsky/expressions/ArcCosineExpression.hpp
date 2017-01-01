#ifndef KANDINSKY_ARCCOSINEEXPRESSION_HPP_
#define KANDINSKY_ARCCOSINEEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    template <class ExpressionType>
    class ArcCosineExpression : public UnaryExpression<ExpressionType>
    {
    public:
        ArcCosineExpression(ExpressionType expression)
            : UnaryExpression<ExpressionType>(expression) {}

        double evaluate() const
        {
            return std::acos(this->m_expression.evaluate());
        }
    };

    template <class ExpressionType>
    ArcCosineExpression<ExpressionType>
    acos(ExpressionType expression)
    {
        return ArcCosineExpression<ExpressionType>(expression);
    }
}

#endif

