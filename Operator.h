#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>

class Operator
{
    private:
        enum ENUM_OPERATOR
        {
            XNOR,
            IMPLICATION,
            OR,
            AND,
            NOT
        } data;
    public:
        inline bool operator>(const Operator& o) const;
        inline bool operator<(const Operator& o) const;
        inline bool operator==(const Operator& o) const;
        inline Operator& operator=(Operator& o);
        inline Operator& operator=(char ch);
        Operator();
        Operator(char ch);
        Operator(const Operator& o);
        inline friend std::string& operator+=(std::string & str, const Operator & op);
};

#endif
