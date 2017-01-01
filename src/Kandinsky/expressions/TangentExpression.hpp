#ifndef KANDINSKY_TANGENTEXPRESSION_HPP_
#define KANDINSKY_TANGENTEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    template <class ExpressionType>
    class TangentExpression : public UnaryExpression<ExpressionType>
    {
    public:
        TangentExpression(ExpressionType expression)
            : UnaryExpression<ExpressionType>(expression) {}

        double evaluate() const
        {
            return std::tan(this->m_expression.evaluate());
        }
    };

    template <class ExpressionType>
    TangentExpression<ExpressionType>
    tan(ExpressionType expression)
    {
        return TangentExpression<ExpressionType>(expression);
    }
}

#endif

