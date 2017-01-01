#ifndef KANDINSKY_BINARYEXPRESSION_HPP_
#define KANDINSKY_BINARYEXPRESSION_HPP_

#include <Kandinsky/expressions/Expression.hpp>
#include <Kandinsky/expressions/ExpressionTraits.hpp>

namespace Kandinsky
{
    template <class ExpressionType1, class ExpressionType2>
    class BinaryExpression : public Expression
    {
    public:
        BinaryExpression(ExpressionType1 expression1, ExpressionType2 expression2)
            : m_expression1(expression1), m_expression2(expression2) {}

    protected:
        typename ExpressionTraits<ExpressionType1>::ExpressionType m_expression1;
        typename ExpressionTraits<ExpressionType2>::ExpressionType m_expression2;
    };
}

#endif

