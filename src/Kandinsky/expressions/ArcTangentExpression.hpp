#ifndef KANDINSKY_ARCTANGENTEXPRESSION_HPP_
#define KANDINSKY_ARCTANGENTEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class ArcTangentExpression : public UnaryExpression
    {
    public:
        ArcTangentExpression(const BaseExpressionPtr& arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::atan(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string toString() const
        {
            return "atan(" + m_arg->toString() + ")";
        }
    };

    template <class ArgT,
            typename std::enable_if<
            std::is_base_of<Variable, ArgT>::value ||
            std::is_base_of<Expression, ArgT>::value ||
            std::is_base_of<BaseExpression, ArgT>::value ||
            std::is_convertible<ArgT, std::shared_ptr<BaseExpression> >::value
            >::type* = nullptr>
    ArcTangentExpression
    atan(const ArgT& arg)
    {
        return ArcTangentExpression(BaseExpression::makePtr(arg));
    }
}

#endif

