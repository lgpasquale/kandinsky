#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>
#include <Kandinsky/expressions/ExpressionTraits.hpp>
#include <Kandinsky/expressions/Constant.hpp>
#include <Kandinsky/expressions/Expression.hpp>
#include <Kandinsky/expressions/Variable.hpp>

namespace Kandinsky
{
    bool VariableLessThanComparator::operator()(const Variable& variable1, const Variable& variable2) const
    {
        return variable1.getIndex() < variable2.getIndex();
    }

    Expression BaseExpression::differentiate(const Variable& variable) const
    {
        return Expression(derivative(variable.getVariableExpressionPtr()));
    }

    std::set<Variable, VariableLessThanComparator> BaseExpression::variables(const std::shared_ptr<BaseExpression>& thisSharedPtr) const
    {
        std::set<Variable, VariableLessThanComparator> variableSet;
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

    size_t BaseExpression::sizeOfAllNodes(
        const std::shared_ptr<BaseExpression>& thisSharedPtr) const
    {
        return sizeOfInternalNodes()
            + numberOfConstants() * sizeof(Constant)
            + variables(thisSharedPtr).size() * sizeof(VariableExpression);
    }
}
