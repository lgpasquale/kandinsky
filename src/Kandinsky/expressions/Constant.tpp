#ifndef KANDINSKY_CONSTANT_TPP_
#define KANDINSKY_CONSTANT_TPP_

#include <Kandinsky/expressions/Constant.hpp>

namespace Kandinsky
{
    BaseExpressionPtr Constant::derivative(const VariableExpressionPtr& /*variable*/) const
    {
        return makePtr(Constant(0));
    }
}

#endif

