#ifndef KANDINSKY_IFTHENELSEEXPRESSION_HPP_
#define KANDINSKY_IFTHENELSEEXPRESSION_HPP_

#include <Kandinsky/expressions/TernaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>
#include <Kandinsky/expressions/Variable.hpp>

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

        virtual std::string toString(bool evaluate = false) const
        {
            return "(" + m_arg1->toString(evaluate) + " ? " + m_arg2->toString(evaluate) + " : " + m_arg3->toString(evaluate) + ")";
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
    Expression
    ifThenElse(const Arg1T& arg1, const Arg2T& arg2, const Arg3T& arg3)
    {
        BaseExpressionPtr arg1Ptr = BaseExpression::makePtr(arg1);
        BaseExpressionPtr arg2Ptr = BaseExpression::makePtr(arg2);
        BaseExpressionPtr arg3Ptr = BaseExpression::makePtr(arg3);
        if (bool(std::dynamic_pointer_cast<Constant>(arg1Ptr)))
        {
            if (bool(arg1Ptr->evaluate()))
                return Expression(arg2);
            else
                return Expression(arg3);
        }
        return Expression(IfThenElseExpression(arg1Ptr, arg2Ptr, arg3Ptr));
    }
}

#endif
