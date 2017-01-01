#ifndef KANDINSKY_COSINEEXPRESSION_HPP_
#define KANDINSKY_COSINEEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    template <class ExpressionType>
    class CosineExpression : public UnaryExpression<ExpressionType>
    {
    public:
        CosineExpression(ExpressionType expression)
            : UnaryExpression<ExpressionType>(expression) {}

        double evaluate() const
        {
            return std::cos(this->m_expression.evaluate());
        }
    };

    template <class ExpressionType>
    CosineExpression<ExpressionType>
    cos(ExpressionType expression)
    {
        return CosineExpression<ExpressionType>(expression);
    }
}

#endif

