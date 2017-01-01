#ifndef KANDINSKY_CONSTANT_HPP_
#define KANDINSKY_CONSTANT_HPP_

namespace Kandinsky
{
    class Constant : public Expression
    {
    public:
        Constant(double value) : m_value(value) {}

        double evaluate() const
        {
            return m_value;
        }

    private:
        double m_value;
    };
}

#endif

