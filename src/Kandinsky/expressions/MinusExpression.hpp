#ifndef KANDINSKY_MINUSEXPRESSION_HPP_
#define KANDINSKY_MINUSEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

namespace Kandinsky
{
    template <class ExpressionType>
    class MinusExpression : public UnaryExpression<ExpressionType>
    {
    public:
        MinusExpression(ExpressionType expression)
            : UnaryExpression<ExpressionType>(expression) {}

        double evaluate() const
        {
            return -this->m_expression.evaluate();
        }
    };

    template <class ExpressionType>
    MinusExpression<ExpressionType> operator-(ExpressionType expression)
    {
        return MinusExpression<ExpressionType>(expression);
    }
}

#endif

