#ifndef KANDINSKY_VARIABLEEXPRESSION_TPP_
#define KANDINSKY_VARIABLEEXPRESSION_TPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/Variable.hpp>

namespace Kandinsky
{
    BaseExpressionPtr VariableExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(Constant(variable.get() == this));
    }

    void VariableExpression::fillVariableSet(std::set<Variable>& variableSet, const BaseExpressionPtr& thisSharedPtr) const
    {
        variableSet.insert(Variable(std::dynamic_pointer_cast<VariableExpression>(thisSharedPtr)));
    }
}

#endif

