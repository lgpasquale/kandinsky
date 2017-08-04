#include <Kandinsky/expressions/Expression.hpp>
#include <Kandinsky/expressions/Variable.hpp>

namespace Kandinsky
{
    std::map<Variable, Expression, VariableLessThanComparator> Expression::derivatives() const
    {
        std::map<Variable, Expression, VariableLessThanComparator> derivativeMap;
        std::set<Variable, VariableLessThanComparator> variableSet = variables();
        for (auto& variable : variableSet)
        {
            derivativeMap.insert(std::make_pair(variable, differentiate(variable)));
        }
        return derivativeMap;
    }

    std::ostream& operator<< (std::ostream& stream, const Expression& expression) {
        stream << expression.toString();
    }
}


