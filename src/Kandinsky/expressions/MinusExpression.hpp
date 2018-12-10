#ifndef KANDINSKY_MINUSEXPRESSION_HPP_
#define KANDINSKY_MINUSEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

namespace Kandinsky
{
    class MinusExpression : public UnaryExpression
    {
    public:
        MinusExpression(const BaseExpressionPtr& arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return -m_arg->evaluate();
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string toString(bool evaluate = false) const
        {
            return "- " + m_arg->toString(evaluate);
        }
    };

    template <class ArgT,
            typename std::enable_if<
            std::is_base_of<Variable, ArgT>::value ||
            std::is_base_of<Expression, ArgT>::value ||
            std::is_base_of<BaseExpression, ArgT>::value ||
            std::is_convertible<ArgT, std::shared_ptr<BaseExpression> >::value
            >::type* = nullptr>
    MinusExpression operator-(const ArgT& arg)
    {
        return MinusExpression(BaseExpression::makePtr(arg));
    }
}

#endif

