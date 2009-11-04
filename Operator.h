#ifndef OPERATOR_H
#define OPERATOR_H

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
        bool operator>(const Operator& o) const;
        bool operator<(const Operator& o) const;
        bool operator==(const Operator& o) const;
        Operator& operator=(Operator& o);
        Operator& operator=(char ch);
};

#endif
