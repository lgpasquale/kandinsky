#ifndef KANDINSKY_ADDITIONEXPRESSION_HPP_
#define KANDINSKY_ADDITIONEXPRESSION_HPP_

#include <Kandinsky/expressions/BinaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>
#include <Kandinsky/expressions/Expression.hpp>

namespace Kandinsky
{
    class AdditionExpression : public BinaryExpression
    {
    public:
        AdditionExpression(const BaseExpressionPtr& arg1, const BaseExpressionPtr& arg2)
            : BinaryExpression(arg1, arg2) {}

        double evaluate() const
        {
            return m_arg1->evaluate() + m_arg2->evaluate();
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string toString(bool evaluate = false) const
        {
            return "(" + m_arg1->toString(evaluate) + " + " + m_arg2->toString(evaluate) + ")";
        }
    };

    template <class Arg1T, class Arg2T,
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
    Expression
    operator+(const Arg1T& arg1, const Arg2T& arg2)
    {
        BaseExpressionPtr arg1Ptr = BaseExpression::makePtr(arg1);
        BaseExpressionPtr arg2Ptr = BaseExpression::makePtr(arg2);
        if (arg1Ptr->isConstant() && arg2Ptr->isConstant())
            return Expression(arg1Ptr->evaluate() + arg2Ptr->evaluate());
        if (arg1Ptr->isConstant() && arg1Ptr->evaluate() == 0)
            return Expression(arg2);
        if (arg2Ptr->isConstant() && arg2Ptr->evaluate() == 0)
            return Expression(arg1);
        return Expression(AdditionExpression(arg1Ptr, arg2Ptr));
    }

    template <class ArgT,
            typename std::enable_if<
            std::is_base_of<Variable, ArgT>::value ||
            std::is_base_of<Expression, ArgT>::value ||
            std::is_base_of<BaseExpression, ArgT>::value ||
            std::is_convertible<ArgT, std::shared_ptr<BaseExpression> >::value
            >::type* = nullptr>
    ArgT
    operator+(const ArgT& arg)
    {
        return arg;
    }

    template <class Arg1T, class Arg2T,
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
    Arg1T&
    operator+=(Arg1T& arg1, const Arg2T& arg2)
    {
        arg1 = arg1 + arg2;
        return arg1;
    }
}

#endif
