#ifndef KANDINSKY_MINUSEXPRESSION_HPP_
#define KANDINSKY_MINUSEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

namespace Kandinsky
{
    class MinusExpression : public UnaryExpression
    {
    public:
        MinusExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return -m_arg->evaluate();
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return "- " + m_arg->print();
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

