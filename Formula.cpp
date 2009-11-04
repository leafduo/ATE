#include "Formula.h"

inline bool Formula::empty() const
{
    return formula.empty();
}

/*inline bool Formula::isRPN() const
{
    return !RPN.empty();
}*/

bool Formula::convertRPN()
{
    //std::stack<char> op;
    return true;
}

inline bool Formula::setVar:()
{
    if (var <= maxVar) {
        ++var;
        return true;
    } else
        return false;
}

inline bool Formula::getVar()
{
    //TODO:get a single bit from var
}

std::istream& operator>>(std::istream& in, Formula& f)
{
    std::string str;
    in >> str;
    f.formula = str;
    f.convertRPN();
    return in;
}

std::ostream& operator<<(std::ostream& out, const Formula& f)
{
    out << f.formula;
    return out;
}

Formula& Formula::operator=(const Formula& f)
{
    formula = f.formula;
    RPN = f.RPN;
    return *this;
}

Formula& Formula::operator=(const char str[])
{
    formula = str;
    return *this;
}

bool Formula::operator==(const Formula& f) const
{
    return true;
}

Formula::Formula(const std::string& str)
{
    Formula();
    formula = str;
    convertRPN();
}

Formula::Formula()
{}

Formula::~Formula()
{}

Formula::Formula(const Formula& f)
{
    Formula();
    *this = f;
}
