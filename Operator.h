#ifndef OPERATOR_H
#define OPERATOR_H

#include "Op.h"

class Operator : public Op
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
        inline Operator& operator=(const Operator& o);
        inline Operator& operator=(char ch);
};

#endif
