#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>
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

