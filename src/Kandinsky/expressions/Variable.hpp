#ifndef KANDINSKY_VARIABLE_HPP_
#define KANDINSKY_VARIABLE_HPP_

namespace Kandinsky
{
    class Variable : public Expression
    {
    public:
        Variable() : m_value(0) {}
        Variable(double value) : m_value(value) {}

        void setValue(double value)
        {
            m_value = value;
        }

        double getValue() const
        {
            return m_value;
        }

        double evaluate() const
        {
            return m_value;
        }

    private:
        double m_value;
    };
}

#endif

