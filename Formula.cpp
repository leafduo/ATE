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
    }
    while (!op.empty()) {
        RPN += op.top();
        op.pop();
    }
#ifdef DEBUG
    std::cout << RPN << std::endl;
#endif
    //TODO:move to another place
    initVar();
#ifdef DEBUG
    for(std::vector<char>::iterator it = privateVariable.begin(); it != privateVariable.end(); ++it)
        std::cout << *it;
    std::cout << std::endl;
#endif
}

void Formula::initVar()   //form a sorted varible name vector
{
    for(std::string::iterator it = formula.begin(); it != formula.end(); ++it)
        if(std::isalpha(*it))
            privateVariable.push_back(*it);
    std::sort(privateVariable.begin(), privateVariable.end());
    std::vector<char>::iterator newEnd = std::unique(privateVariable.begin(), privateVariable.end());
    privateVariable.erase(newEnd, privateVariable.end());
}


std::istream& operator>>(std::istream& in, Formula& f)
{
    std::string str;
    in >> str;
    std::for_each(str.begin(), str.end(), Formula::tolower); 
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
    convertRPN();
    return *this;
}

Formula& Formula::operator=(const char str[])
{
    /*int i;
    for(i = 0; str[i] != 0; ++i)
        ;
    std::for_each(str, str + i, tolower); */
    formula = str;
    std::for_each(formula.begin(), formula.end(), Formula::tolower);
    convertRPN();
    return *this;
}

bool Formula::operator==(const Formula& f) const
{
    initMaxVar(f);
#ifdef DEBUG
    std::cout << "maxVar = " << maxVar << std::endl;
#endif
    for (var = 0; var != maxVar; ++var) {
        setValue();
#ifdef DEBUG
        std::cout << "hit" << std::endl;
#endif
        if (f.evaluate() != evaluate())
            return false;
    }
    return true;
}

void Formula::initMaxVar(const Formula f) const
{
    std::merge(privateVariable.begin(), privateVariable.end(), f.privateVariable.begin(), f.privateVariable.end(), back_inserter(Formula::variable));
    std::vector<char>::iterator newEnd = std::unique(Formula::variable.begin(), Formula::variable.end());
    Formula::variable.erase(newEnd, variable.end());
    unsigned length = Formula::variable.size();
    Formula::maxVar = ~(~0uL>>length<<length); //form maxVar
#ifdef DEBUG
    std::cout << Formula::maxVar << std::endl;
#endif
}

bool Formula::evaluate(void) const
{
    std::string f = replace();
#ifdef DEBUG
    std::cout << "f:" << f << std::endl;
#endif
    std::stack<bool> st;
    for (std::string::iterator it = f.begin(); it != f.end(); ++it) {
        if (isOperand(*it))
            st.push(bool(*it-'0'));
        else if('!' == *it) {
            bool o = st.top();
            st.pop();
            st.push(!o);
        } else {
            Operator op(*it);
            bool o1, o2;
            o2 = st.top();
            st.pop();
            o1 = st.top();
            st.pop();
            st.push(op(o1, o2));
        }
    }
    return st.top();
}

std::string Formula::replace(void) const
{
    std::string result(RPN);
    for(std::vector<char>::iterator i = variable.begin(); i != variable.end(); ++i)
        std::replace(result.begin(), result.end(), *i, getVar(*i));
    return result;
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

void Formula::tolower(char& ch)
{
    ch = std::tolower(ch);
}

unsigned Formula::var = 0;
unsigned Formula::maxVar;
std::vector<char> Formula::variable;
std::bitset<26> Formula::value;
