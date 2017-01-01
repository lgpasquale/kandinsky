#ifndef KANDINSKY_ABSEXPRESSION_HPP_
#define KANDINSKY_ABSEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    template <class ExpressionType>
    class AbsExpression : public UnaryExpression<ExpressionType>
    {
    public:
        AbsExpression(ExpressionType expression)
            : UnaryExpression<ExpressionType>(expression) {}

        double evaluate() const
        {
            return std::abs(this->m_expression.evaluate());
        }
    };

    template <class ExpressionType>
    AbsExpression<ExpressionType> abs(ExpressionType expression)
    {
        return AbsExpression<ExpressionType>(expression);
    }
}

#endif

