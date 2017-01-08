#ifndef KANDINSKY_SINEEXPRESSION_HPP_
#define KANDINSKY_SINEEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class SineExpression : public UnaryExpression
    {
    public:
        SineExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::sin(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "sin(" + m_arg->print() + ")";
        }
    };

    template <class ArgT>
    SineExpression
    sin(ArgT arg)
    {
        return SineExpression(BaseExpression::makePtr(arg));
    }
}

#endif

