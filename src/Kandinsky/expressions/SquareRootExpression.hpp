#ifndef KANDINSKY_SQUAREROOTEXPRESSION_HPP_
#define KANDINSKY_SQUAREROOTEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class SquareRootExpression : public UnaryExpression
    {
    public:
        SquareRootExpression(const BaseExpressionPtr& arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return std::sqrt(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string toString() const
        {
            return "sqrt(" + m_arg->toString() + ")";
        }
    };

    template <class ArgT,
            typename std::enable_if<
            std::is_base_of<Variable, ArgT>::value ||
            std::is_base_of<Expression, ArgT>::value ||
            std::is_base_of<BaseExpression, ArgT>::value ||
            std::is_convertible<ArgT, std::shared_ptr<BaseExpression> >::value
            >::type* = nullptr>
    SquareRootExpression
    sqrt(const ArgT& arg)
    {
        return SquareRootExpression(BaseExpression::makePtr(arg));
    }
}

#endif

