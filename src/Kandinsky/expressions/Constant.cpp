#include <Kandinsky/expressions/Constant.hpp>
#include <Kandinsky/expressions/VariableExpression.hpp>
#include <Kandinsky/expressions/BaseExpression.tpp>

namespace Kandinsky
{
    BaseExpressionPtr Constant::derivative(const VariableExpressionPtr& /*variable*/) const
    {
        return makePtr(Constant(0));
    }
}

