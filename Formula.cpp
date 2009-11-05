#include "Formula.h"
#include "Operator.h"
#include "Operand.h"

#include <vector>
#include <algorithm>
#include <cctype>

inline bool Formula::empty() const
{
    return formula.empty();
}

/*inline bool Formula::isRPN() const
{
    return !RPN.empty();
}*/

inline bool Formula::isOperator(char ch) const
{
    if ('!' == ch || '&' == ch || '|' == ch || '-' == ch || '<' == ch)
        return true;
    else
        return false;
}

inline bool Formula::isOperand(char ch) const
{
    if (isalpha(ch) || '0' == ch || '1' == ch)
        return true;
    else
        return false;
}

void Formula::convertRPN()
{
    std::stack<Operator, std::vector<Operator> > op;
    for (std::string::iterator it = formula.begin(); it != formula.end(); ++it) {
        if (isOperand(*it)) {
            Op *tmp = new Operand(*it);
            RPN.push_back(tmp);
        } else if (isOperator(*it)) {
            Op *tmp = new Operator(*it);
            if (!op.empty() && op.top() > *tmp) {
                Op *tmp2 = new Operator(op.top());
                RPN.push_back(tmp2);
                op.pop();
            }
            op.push(*tmp);
        } else
            assert(isspace(*it));
        while (!op.empty()) {
            Op *tmp = new Operator(op.top());
            RPN.push_back(tmp);
            op.pop();
        }
}

inline bool Formula::setVar()
{
    if (var <= maxVar) {
        ++var;
        return true;
    } else
        return false;
}

inline bool Formula::getVar(int i)
{
    return var & (1u << i);
}

std::istream& operator>>(std::istream& in, Formula& f)
{
    std::string str;
    in >> str;
    for_each(str.begin(), str.end(), std::tolower); 
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
    var = 0;
    for (;setVar;)
        if (f.evalution() != evalution())
            return false;
    return true;
}

bool Formula::evalution() const
{
    //TODO
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
