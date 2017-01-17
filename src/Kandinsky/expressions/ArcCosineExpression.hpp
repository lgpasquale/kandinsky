#ifndef KANDINSKY_ARCCOSINEEXPRESSION_HPP_
#define KANDINSKY_ARCCOSINEEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class ArcCosineExpression : public UnaryExpression
    {
    public:
        ArcCosineExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::acos(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "acos(" + m_arg->print() + ")";
        }
    };

    template <class ArgT,
            typename std::enable_if<
            std::is_base_of<Variable, ArgT>::value ||
            std::is_base_of<Expression, ArgT>::value ||
            std::is_base_of<BaseExpression, ArgT>::value ||
            std::is_convertible<ArgT, std::shared_ptr<BaseExpression> >::value
            >::type* = nullptr>
    ArcCosineExpression
    acos(const ArgT& arg)
    {
        return ArcCosineExpression(BaseExpression::makePtr(arg));
    }
}

#endif

