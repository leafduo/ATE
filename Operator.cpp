#include <cassert>

#include "Operator.h"

bool Operator::operator()(bool o1, bool o2) const
{
    if (XNOR == data)
        return o1 ^ o2;
    else if (IMPLICATION == data) {
        if (!o1)
            return true;
        else if (o2)
            return true;
        else
            return false;
    } else if (OR == data)
        return o1 || o2;
    else if (AND == data)
        return o1 && o2;
    else
        assert(false);
}

bool Operator::operator()(bool o) const
{
    assert(NOT == data);
    return !o;
}
