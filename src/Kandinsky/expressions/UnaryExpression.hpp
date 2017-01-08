#ifndef KANDINSKY_UNARYEXPRESSION_HPP_
#define KANDINSKY_UNARYEXPRESSION_HPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/ExpressionTraits.hpp>

namespace Kandinsky
{
    class UnaryExpression : public BaseExpression
    {
    public:
        UnaryExpression(BaseExpressionPtr arg)
            : m_arg(arg) {}

    protected:
        BaseExpressionPtr m_arg;
    };
}

#endif

