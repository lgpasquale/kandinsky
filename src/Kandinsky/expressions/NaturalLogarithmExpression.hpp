#ifndef KANDINSKY_NATURALLOGARITHMEXPRESSION_HPP_
#define KANDINSKY_NATURALLOGARITHMEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    template <class ExpressionType>
    class NaturalLogarithmExpression : public UnaryExpression<ExpressionType>
    {
    public:
        NaturalLogarithmExpression(ExpressionType expression)
            : UnaryExpression<ExpressionType>(expression) {}

        double evaluate() const
        {
            return std::log(this->m_expression.evaluate());
        }
    };

    template <class ExpressionType>
    NaturalLogarithmExpression<ExpressionType>
    log(ExpressionType expression)
    {
        return NaturalLogarithmExpression<ExpressionType>(expression);
    }
}

#endif

