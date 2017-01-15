#include <Kandinsky/expressions/logical/AndExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>
#include <Kandinsky/expressions/Constant.hpp>

namespace Kandinsky
{
    BaseExpressionPtr AndExpression::derivative(const VariableExpressionPtr& /*variable*/) const
    {
        return makePtr(Constant(0));
    }
}

