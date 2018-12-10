#ifndef KANDINSKY_NOTEXPRESSION_HPP_
#define KANDINSKY_NOTEXPRESSION_HPP_

#include <Kandinsky/expressions/UnaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>
#include <Kandinsky/expressions/Expression.hpp>

#include <cmath>

namespace Kandinsky
{
    class NotExpression : public UnaryExpression
    {
    public:
        NotExpression(BaseExpressionPtr arg)
            : UnaryExpression(arg) {}

        double evaluate() const
        {
            return !(m_arg->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string toString(bool evaluate = false) const
        {
            return "!" + m_arg->toString(evaluate);
        }
    };

    template <class ArgT,
            typename std::enable_if<
            std::is_base_of<Variable, ArgT>::value ||
            std::is_base_of<Expression, ArgT>::value ||
            std::is_base_of<BaseExpression, ArgT>::value ||
            std::is_convertible<ArgT, std::shared_ptr<BaseExpression> >::value
            >::type* = nullptr>
    Expression
    operator!(const ArgT& arg)
    {
        BaseExpressionPtr argPtr = BaseExpression::makePtr(arg);
        if (bool(std::dynamic_pointer_cast<Constant>(argPtr)))
            return Expression(Constant(!argPtr->evaluate()));
        return Expression(NotExpression(argPtr));
    }
}

#endif
