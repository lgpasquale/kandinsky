#ifndef KANDINSKY_BASEEXPRESSION_TPP_
#define KANDINSKY_BASEEXPRESSION_TPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/ExpressionTraits.hpp>
#include <Kandinsky/expressions/Expression.hpp>
#include <Kandinsky/expressions/Variable.hpp>

namespace Kandinsky
{
    Expression BaseExpression::differentiate(const Variable& variable) const
    {
        return Expression(derivative(variable.getVariableExpressionPtr()));
    }

    std::set<Variable> BaseExpression::variables(const std::shared_ptr<BaseExpression>& thisSharedPtr) const
    {
        std::set<Variable> variableSet;
        fillVariableSet(variableSet, thisSharedPtr);
        return variableSet;
    }

    template <class T> struct is_shared_ptr : std::false_type {};
    template <class T> struct is_shared_ptr<std::shared_ptr<T> > : std::true_type {};

    template <class T>
    std::shared_ptr<BaseExpression> makePtr2(const T& arg, std::false_type)
    {
        return std::shared_ptr<BaseExpression>(new typename ExpressionTraits<T>::ExpressionType(arg));
    }

    template <class T>
    std::shared_ptr<BaseExpression> makePtr2(const T& arg, std::true_type)
    {
        return arg;
    }

    template <class T>
    std::shared_ptr<BaseExpression> BaseExpression::makePtr(const T& arg)
    {
        return makePtr2(arg, is_shared_ptr<T>{});
    }

    template <>
    std::shared_ptr<BaseExpression> BaseExpression::makePtr<Variable>(const Variable& arg)
    {
        return arg.getVariableExpressionPtr();
    }

    template <>
    std::shared_ptr<BaseExpression> BaseExpression::makePtr<Expression>(const Expression& arg)
    {
        return arg.getBaseExpressionPtr();
    }

}

#endif
