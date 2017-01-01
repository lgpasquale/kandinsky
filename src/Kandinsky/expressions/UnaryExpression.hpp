#ifndef KANDINSKY_UNARYEXPRESSION_HPP_
#define KANDINSKY_UNARYEXPRESSION_HPP_

#include <Kandinsky/expressions/Expression.hpp>
#include <Kandinsky/expressions/ExpressionTraits.hpp>

namespace Kandinsky
{
    template <class ExpressionType>
    class UnaryExpression : public Expression
    {
    public:
        UnaryExpression(ExpressionType expression)
            : m_expression(expression) {}

    protected:
        typename ExpressionTraits<ExpressionType>::ExpressionType m_expression;
    };
}

#endif

