#ifndef KANDINSKY_SQUAREROOTEXPRESSION_HPP_
#define KANDINSKY_SQUAREROOTEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    template <class ExpressionType>
    class SquareRootExpression : public UnaryExpression<ExpressionType>
    {
    public:
        SquareRootExpression(ExpressionType expression)
            : UnaryExpression<ExpressionType>(expression) {}

        double evaluate() const
        {
            return std::sqrt(this->m_expression.evaluate());
        }
    };

    template <class ExpressionType>
    SquareRootExpression<ExpressionType>
    sqrt(ExpressionType expression)
    {
        return SquareRootExpression<ExpressionType>(expression);
    }
}

#endif

