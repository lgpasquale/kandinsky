#ifndef KANDINSKY_SINEEXPRESSION_HPP_
#define KANDINSKY_SINEEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class SineExpression : public UnaryExpression
    {
    public:
        SineExpression(const BaseExpressionPtr& arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::sin(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string toString(bool evaluate = false) const
        {
            return "sin(" + m_arg->toString(evaluate) + ")";
        }
    };

    template <class ArgT,
            typename std::enable_if<
            std::is_base_of<Variable, ArgT>::value ||
            std::is_base_of<Expression, ArgT>::value ||
            std::is_base_of<BaseExpression, ArgT>::value ||
            std::is_convertible<ArgT, std::shared_ptr<BaseExpression> >::value
            >::type* = nullptr>
    SineExpression
    sin(const ArgT& arg)
    {
        return SineExpression(BaseExpression::makePtr(arg));
    }
}

#endif

