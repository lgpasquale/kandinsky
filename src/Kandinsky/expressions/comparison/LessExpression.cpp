#include <Kandinsky/expressions/comparison/LessExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>
#include <Kandinsky/expressions/Constant.hpp>

namespace Kandinsky
{
    BaseExpressionPtr LessExpression::derivative(const VariableExpressionPtr& /*variable*/) const
    {
        return makePtr(Constant(0));
    }
}

