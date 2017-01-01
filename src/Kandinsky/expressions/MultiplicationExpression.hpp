#ifndef KANDINSKY_MULTIPLICATIONEXPRESSION_HPP_
#define KANDINSKY_MULTIPLICATIONEXPRESSION_HPP_

namespace Kandinsky
{
    template <class ExpressionType1, class ExpressionType2>
    class MultiplicationExpression : public BinaryExpression<ExpressionType1, ExpressionType2>
    {
    public:
        MultiplicationExpression(ExpressionType1 expression1, ExpressionType2 expression2)
            : BinaryExpression<ExpressionType1, ExpressionType2>(expression1, expression2) {}

        double evaluate() const
        {
            return this->m_expression1.evaluate() * this->m_expression2.evaluate();
        }
    };

    template <class ExpressionType1,class ExpressionType2>
    MultiplicationExpression<ExpressionType1, ExpressionType2 >
    operator*(ExpressionType1 expression1, ExpressionType2 expression2)
    {
        return MultiplicationExpression<ExpressionType1, ExpressionType2>(expression1, expression2);
    }
}

#endif

