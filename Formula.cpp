#include "Formula.h"
#include "Operator.h"

#include <vector>
#include <algorithm>
#include <cctype>
#include <stack>
#include <cassert>

#ifdef DEBUG
#include <iostream>
#endif

void Formula::convertRPN()
{
    std::stack<Operator, std::vector<Operator> > op;
    for (std::string::iterator it = formula.begin(); it != formula.end(); ++it) {
        if (isOperand(*it)) {
            RPN += *it;
        } else if (isOperator(*it)) {
            Operator tmp(*it);
            if (!op.empty() && op.top() > tmp) {
                RPN += op.top();
                op.pop();
            }
            op.push(tmp);
            if('-' == *it)
                ++it;   //TODO:error handling 
        } else if ('(' == *it) {
            Operator tmp(*it);
            op.push(tmp);
        } else if (')' == *it) { //TODO:error handling
            Operator pare('(');
            while(pare != op.top()) {
                RPN += op.top();
                op.pop();
            }
            op.pop();
        } else
            assert(isspace(*it));
        RPN += " ";
#ifdef DEBUG
        std::cout<<RPN<<std::endl;
#endif
    }
    while (!op.empty()) {
        RPN += op.top();
        RPN += " ";
        op.pop();
    }

}

void Formula::initVar()   //form a sorted varible name vector
{
    for(std::string::iterator it = formula.begin(); it != formula.end(); ++it)
        if(std::isalpha(*it))
            variable.push_back(*it);
    std::sort(variable.begin(), variable.end());
    std::vector<char>::iterator newEnd = std::unique(variable.begin(), variable.end());
    variable.erase(newEnd, variable.end());
}
    

std::istream& operator>>(std::istream& in, Formula& f)
{
    std::string str;
    in >> str;
    for_each(str.begin(), str.end(), tolower); 
    f.formula = str;
    f.convertRPN();
#ifdef DEBUG
    std::cout<<f.RPN<<std::endl;
#endif
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
        if (f.evaluate() != evaluate())
            return false;
    return true;
}

bool Formula::evaluate() const
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
{
}


Formula::~Formula()
{}

Formula::Formula(const Formula& f)
{
    Formula();
    *this = f;
}

unsigned Formula::var = 0;
unsigned Formula::maxVar = 0; //FIXME:should be deleted
