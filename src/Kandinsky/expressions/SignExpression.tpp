#ifndef KANDINSKY_SIGNEXPRESSION_TPP_
#define KANDINSKY_SIGNEXPRESSION_TPP_

#include <Kandinsky/expressions/SignExpression.hpp>

namespace Kandinsky
{
    BaseExpressionPtr SignExpression::derivative(const VariableExpressionPtr& /*variable*/) const
    {
        return BaseExpression::makePtr(Constant(0));
    }
}

#endif

