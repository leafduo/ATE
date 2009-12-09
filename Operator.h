#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <cassert>

enum ENUM_OPERATOR
{
    XNOR,
    IMPLICATION,
    OR,
    AND,
    NOT
};

class Operator
{
    private:
        ENUM_OPERATOR data;
    public:
        inline bool operator>(const Operator& o) const;
        inline bool operator<(const Operator& o) const;
        inline bool operator==(const Operator& o) const;
        inline Operator& operator=(const Operator& o);
        inline Operator& operator=(char ch);
        Operator();
        Operator(char ch);
        Operator(const Operator& o);
        inline friend std::string& operator+=(std::string & str, const Operator & op);
};

inline Operator::Operator(const Operator& o)
{
    *this = o;
}

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

inline Operator& Operator::operator=(const Operator& o)
{
    data = o.data;
    return *this;
}

inline Operator& Operator::operator=(char ch)
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
    if (XNOR == op.data)
        return str += '^';
    else if (IMPLICATION == op.data)
        return str += '-';
    else if (OR == op.data)
        return str += '|';
    else if (AND == op.data)
        return str += '&';
    else if (NOT == op.data)
        return str += '!';
    else
        assert(false);
}


#endif
