#ifndef KANDINSKY_DIVISIONEXPRESSION_HPP_
#define KANDINSKY_DIVISIONEXPRESSION_HPP_

#include <Kandinsky/expressions/BinaryExpression.hpp>

namespace Kandinsky
{
    template <class ExpressionType1, class ExpressionType2>
    class DivisionExpression : public BinaryExpression<ExpressionType1, ExpressionType2>
    {
    public:
        DivisionExpression(ExpressionType1 expression1, ExpressionType2 expression2)
            : BinaryExpression<ExpressionType1, ExpressionType2>(expression1, expression2) {}

        double evaluate() const
        {
            return this->m_expression1.evaluate() / this->m_expression2.evaluate();
        }
    };

    template <class ExpressionType1,class ExpressionType2>
    DivisionExpression<ExpressionType1, ExpressionType2 >
    operator/(ExpressionType1 expression1, ExpressionType2 expression2)
    {
        return DivisionExpression<ExpressionType1, ExpressionType2>(expression1, expression2);
    }
}

#endif

