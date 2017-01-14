#ifndef KANDINSKY_SIGNEXPRESSION_HPP_
#define KANDINSKY_SIGNEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class SignExpression : public UnaryExpression
    {
    public:
        SignExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return (m_arg->evaluate() >= 0) ? 1. : -1;
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "sign(" + m_arg->print() + ")";
        }
    };

    template <class ArgT>
    SignExpression sign(const ArgT& arg)
    {
        return SignExpression(BaseExpression::makePtr(arg));
    }
}

#endif

