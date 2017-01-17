#ifndef KANDINSKY_IFTHENELSEEXPRESSION_HPP_
#define KANDINSKY_IFTHENELSEEXPRESSION_HPP_

#include <Kandinsky/expressions/TernaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

namespace Kandinsky
{
    class IfThenElseExpression : public TernaryExpression
    {
    public:
        IfThenElseExpression(const BaseExpressionPtr& arg1, const BaseExpressionPtr& arg2, const BaseExpressionPtr& arg3)
            : TernaryExpression(arg1, arg2, arg3) {}

        double evaluate() const
        {
            return m_arg1->evaluate() ? m_arg2->evaluate() : m_arg3->evaluate();
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string toString() const
        {
            return "(" + m_arg1->toString() + " ? " + m_arg2->toString() + " : " + m_arg3->toString() + ")";
        }
    };

    template <class Arg1T, class Arg2T, class Arg3T,
            typename std::enable_if<
            std::is_base_of<Variable, Arg1T>::value ||
            std::is_base_of<Variable, Arg2T>::value ||
            std::is_base_of<Variable, Arg3T>::value ||
            std::is_base_of<Expression, Arg1T>::value ||
            std::is_base_of<Expression, Arg2T>::value ||
            std::is_base_of<Expression, Arg3T>::value ||
            std::is_base_of<BaseExpression, Arg1T>::value ||
            std::is_base_of<BaseExpression, Arg2T>::value ||
            std::is_base_of<BaseExpression, Arg3T>::value ||
            std::is_convertible<Arg1T, std::shared_ptr<BaseExpression> >::value ||
            std::is_convertible<Arg2T, std::shared_ptr<BaseExpression> >::value ||
            std::is_convertible<Arg3T, std::shared_ptr<BaseExpression> >::value
            >::type* = nullptr>
    IfThenElseExpression
    ifThenElse(const Arg1T& arg1, const Arg2T& arg2, const Arg3T& arg3)
    {
        return IfThenElseExpression(BaseExpression::makePtr(arg1), BaseExpression::makePtr(arg2), BaseExpression::makePtr(arg3));
    }
}

#endif

