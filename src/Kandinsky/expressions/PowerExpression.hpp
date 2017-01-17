#ifndef KANDINSKY_POWEREXPRESSION_HPP_
#define KANDINSKY_POWEREXPRESSION_HPP_

#include <Kandinsky/expressions/BinaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

#include <cmath>

namespace Kandinsky
{
    class PowerExpression : public BinaryExpression
    {
    public:
        PowerExpression(const BaseExpressionPtr& arg1, const BaseExpressionPtr& arg2)
            : BinaryExpression(arg1, arg2) {}

        double evaluate() const
        {
            return std::pow(m_arg1->evaluate(), m_arg2->evaluate());
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string toString() const
        {
            return "pow(" + m_arg1->toString() + ", " + m_arg2->toString() + ")";
        }
    };

    template <class Arg1T,class Arg2T,
            typename std::enable_if<
            std::is_base_of<Variable, Arg1T>::value ||
            std::is_base_of<Variable, Arg2T>::value ||
            std::is_base_of<Expression, Arg1T>::value ||
            std::is_base_of<Expression, Arg2T>::value ||
            std::is_base_of<BaseExpression, Arg1T>::value ||
            std::is_base_of<BaseExpression, Arg2T>::value ||
            std::is_convertible<Arg1T, std::shared_ptr<BaseExpression> >::value ||
            std::is_convertible<Arg2T, std::shared_ptr<BaseExpression> >::value
            >::type* = nullptr>
    PowerExpression
    pow(const Arg1T& arg1, const Arg2T& arg2)
    {
        return PowerExpression(BaseExpression::makePtr(arg1), BaseExpression::makePtr(arg2));
    }
}

#endif

