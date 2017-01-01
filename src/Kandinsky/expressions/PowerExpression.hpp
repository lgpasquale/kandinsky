#ifndef KANDINSKY_POWEREXPRESSION_HPP_
#define KANDINSKY_POWEREXPRESSION_HPP_

#include <Kandinsky/expressions/BinaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    template <class ExpressionType1, class ExpressionType2>
    class PowerExpression : public BinaryExpression<ExpressionType1, ExpressionType2>
    {
    public:
        PowerExpression(ExpressionType1 expression1, ExpressionType2 expression2)
            : BinaryExpression<ExpressionType1, ExpressionType2>(expression1, expression2) {}

        double evaluate() const
        {
            return std::pow(this->m_expression1.evaluate(), this->m_expression2.evaluate());
        }
    };

    template <class ExpressionType1,class ExpressionType2>
    PowerExpression<ExpressionType1, ExpressionType2 >
    pow(ExpressionType1 expression1, ExpressionType2 expression2)
    {
        return PowerExpression<ExpressionType1, ExpressionType2>(expression1, expression2);
    }
}

#endif

