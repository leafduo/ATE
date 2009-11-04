#include "Opeartor.h"

inline bool Operator::operator>(const Operator& o) const
{
    return data > o.data;
}

inline bool Operator::operator<(const Operator& o) const
{
    return data < o.data;
}

inline bool Operator::operator==(const Operator& o) const
{
    return data == o.data;
}

inline Operator& operator=(const Operator& o)
{
    data = o.data;
    return *this;
}

inline Operator& operator=(char ch)
{
    switch(ch) {
        default:
            assert(false);
            break;
        case '!':
            data = NOT;
            break;
        case '&':
            data = AND;
            break;
        case '|':
            data = OR;
            break;
        case '-':
            data = IMPLICATION;
            break;
        case '<':
            data = XNOR;
            break;
    }
    return *this;
}
