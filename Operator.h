#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <cassert>

#ifdef DEBUG
#include <iostream>
#endif

enum ENUM_OPERATOR
{
    PARE,
    XNOR,
    IMPLICATION,
    OR,
    AND,
    NOT,
};

class Operator
{
    private:
        ENUM_OPERATOR data;
    public:
        inline bool operator>(const Operator& o) const;
        inline bool operator<(const Operator& o) const;
        inline bool operator==(const Operator& o) const;
        inline bool operator!=(const Operator& o) const;
        inline Operator& operator=(const Operator& o);
        inline Operator& operator=(char ch);
        inline Operator();
        inline Operator(char ch);
        inline Operator(const Operator& o);
        inline friend std::string& operator+=(std::string & str, const Operator & op);
        bool operator()(bool o1, bool o2) const;
        bool operator()(bool o) const;
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

inline bool Operator::operator!=(const Operator& o) const
{
    return data != o.data;
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
        case '^':
            data = XNOR;
            break;
        case '(':
            data = PARE;
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
    else if (PARE == op.data)
        return str += '(';
    else {
#ifdef DEBUG
        std::string tmp(""); 
        std::cout << op.data << std::endl;
#endif
        assert(false);
    }
}

Operator::Operator(char ch)
{
   *this = ch;
}

#endif
