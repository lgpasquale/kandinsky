#ifndef KANDINSKY_EXPRESSION_TPP_
#define KANDINSKY_EXPRESSION_TPP_

#include <Kandinsky/expressions/Expression.hpp>
#include <Kandinsky/expressions/Variable.hpp>

namespace Kandinsky
{
    std::map<Variable, Expression> Expression::derivatives() const
    {
        std::map<Variable, Expression> derivativeMap;
        std::set<Variable> variableSet = variables();
        for (auto& variable : variableSet)
        {
            derivativeMap.insert(std::make_pair(variable, differentiate(variable)));
        }
        return derivativeMap;
    }
}

#endif


