#ifndef KANDINSKY_BASEEXPRESSION_TPP_
#define KANDINSKY_BASEEXPRESSION_TPP_

#include <Kandinsky/expressions/BaseExpression.hpp>
#include <Kandinsky/expressions/ExpressionTraits.hpp>

namespace Kandinsky
{

    template <class T> struct is_shared_ptr : std::false_type {};
    template <class T> struct is_shared_ptr<std::shared_ptr<T> > : std::true_type {};

    template <class T>
    std::shared_ptr<BaseExpression> makePtr2(const T& arg, std::false_type)
    {
        return std::make_shared<typename ExpressionTraits<T>::ExpressionType>(arg);
    }

    template <class T>
    std::shared_ptr<BaseExpression> makePtr2(const T& arg, std::true_type)
    {
        return arg;
    }

    template <class T>
    std::shared_ptr<BaseExpression> BaseExpression::makePtr(const T& arg)
    {
        return makePtr2(arg, is_shared_ptr<T>{});
    }

}

#endif

