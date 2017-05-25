#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/Variable.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr VariableExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(Constant(variable.get() == this));
    }

    void VariableExpression::fillVariableSet(std::set<Variable, VariableLessThanComparator>& variableSet, const BaseExpressionPtr& thisSharedPtr) const
    {
        variableSet.insert(Variable(std::dynamic_pointer_cast<VariableExpression>(thisSharedPtr)));
    }
}
