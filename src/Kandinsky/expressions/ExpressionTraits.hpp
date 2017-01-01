#ifndef KANDINSKY_EXPRESSIONTRAITS_HPP_
#define KANDINSKY_EXPRESSIONTRAITS_HPP_

#include <Kandinsky/expressions/Constant.hpp>

namespace Kandinsky
{
    template <class ExpressionT>
    struct ExpressionTraits
    {
        typedef ExpressionT ExpressionType;
    };

    template <>
    struct ExpressionTraits<int>
    {
        typedef Constant ExpressionType;
    };

    template <>
    struct ExpressionTraits<float>
    {
        typedef Constant ExpressionType;
    };

    template <>
    struct ExpressionTraits<double>
    {
        typedef Constant ExpressionType;
    };

}

#endif

