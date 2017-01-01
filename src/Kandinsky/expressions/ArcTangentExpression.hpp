#ifndef KANDINSKY_ARCTANGENTEXPRESSION_HPP_
#define KANDINSKY_ARCTANGENTEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    template <class ExpressionType>
    class ArcTangentExpression : public UnaryExpression<ExpressionType>
    {
    public:
        ArcTangentExpression(ExpressionType expression)
            : UnaryExpression<ExpressionType>(expression) {}

        double evaluate() const
        {
            return std::atan(this->m_expression.evaluate());
        }
    };

    template <class ExpressionType>
    ArcTangentExpression<ExpressionType>
    atan(ExpressionType expression)
    {
        return ArcTangentExpression<ExpressionType>(expression);
    }
}

#endif

