#ifndef KANDINSKY_VARIABLEEXPRESSION_TPP_
#define KANDINSKY_VARIABLEEXPRESSION_TPP_

#include <Kandinsky/expressions/BaseExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr VariableExpression::derivative(const VariableExpressionPtr& variable) const
    {
        return makePtr(Constant(variable.get() == this));
    }
}

#endif

