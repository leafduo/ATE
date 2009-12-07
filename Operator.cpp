#include <cassert>

#include "Operator.h"

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

inline Operator& operator=(Operator& o)
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

inline std::string& operator+=(std::string & str, const Operator & op)
{
    if (XNOR == op)
        return str += '^';
    else if (IMPLICATION == op)
        return str += '-';
    else if (OR == op)
        return str += '|';
    else if (AND == op)
        return str += '&';
    else if (NOT == op)
        return str += '!';
    else
        assert(false);
}

Operator::Operator()
{}

Operator::Operator(char ch)
{
   *this = ch;
}
