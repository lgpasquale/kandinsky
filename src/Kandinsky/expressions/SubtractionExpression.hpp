#ifndef KANDINSKY_SUBTRACTIONEXPRESSION_HPP_
#define KANDINSKY_SUBTRACTIONEXPRESSION_HPP_

#include <Kandinsky/expressions/BinaryExpression.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>

namespace Kandinsky
{
    class SubtractionExpression : public BinaryExpression
    {
    public:
        SubtractionExpression(const BaseExpressionPtr& arg1, const BaseExpressionPtr& arg2)
            : BinaryExpression(arg1, arg2) {}

        double evaluate() const
        {
            return m_arg1->evaluate() - m_arg2->evaluate();
        }

        virtual BaseExpressionPtr derivative(const VariableExpressionPtr& variable) const;

        virtual std::string print() const
        {
            return m_arg1->print() + " - " + m_arg2->print();
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
    SubtractionExpression
    operator-(const Arg1T& arg1, const Arg2T& arg2)
    {
        return SubtractionExpression(BaseExpression::makePtr(arg1), BaseExpression::makePtr(arg2));
    }

    template <class Arg1T, class Arg2T>
    Arg1T&
    operator-=(Arg1T& arg1, const Arg2T& arg2)
    {
        arg1 = arg1 - arg2;
        return arg1;
    }
}

#endif

