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
        SignExpression(const BaseExpressionPtr& arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return (m_arg->evaluate() >= 0) ? 1. : -1;
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string toString(bool evaluate = false) const
        {
            return "sign(" + m_arg->toString(evaluate) + ")";
        }
    };

    template <class ArgT,
            typename std::enable_if<
            std::is_base_of<Variable, ArgT>::value ||
            std::is_base_of<Expression, ArgT>::value ||
            std::is_base_of<BaseExpression, ArgT>::value ||
            std::is_convertible<ArgT, std::shared_ptr<BaseExpression> >::value
            >::type* = nullptr>
    SignExpression sign(const ArgT& arg)
    {
        return SignExpression(BaseExpression::makePtr(arg));
    }
}

#endif

