#ifndef KANDINSKY_ARCSINEEXPRESSION_HPP_
#define KANDINSKY_ARCSINEEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class ArcSineExpression : public UnaryExpression
    {
    public:
        ArcSineExpression(const BaseExpressionPtr& arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::asin(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "asin(" + m_arg->print() + ")";
        }
    };

    template <class ArgT,
            typename std::enable_if<
            std::is_base_of<Variable, ArgT>::value ||
            std::is_base_of<Expression, ArgT>::value ||
            std::is_base_of<BaseExpression, ArgT>::value ||
            std::is_convertible<ArgT, std::shared_ptr<BaseExpression> >::value
            >::type* = nullptr>
    ArcSineExpression
    asin(const ArgT& arg)
    {
        return ArcSineExpression(BaseExpression::makePtr(arg));
    }
}

#endif

