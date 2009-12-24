#ifndef FORMULA_H
#define FORMULA_H

#include <string>
#include <vector>
#include <list>
#include <istream>
#include <ostream>
#include <bitset>

class Formula
{
    private:
        //inline bool isRPN() const;
        inline bool empty() const;
        bool evaluate() const;
        void convertRPN();
        inline bool isOperator(char ch) const;
        inline bool isOperand(char ch) const;
        static inline bool setVar();
        static inline bool getVar(char ch);
        void initVar();
        void initMaxVar(const Formula f) const;
        static unsigned var;
        static unsigned maxVar;
        std::vector<char> privateVariable;
        static std::vector<char> variable;
        static std::bitset<26> value;
        static void tolower(char& ch);
        std::string formula;
        std::string RPN;
    public:
        Formula();
        ~Formula();
        Formula(const std::string& str);
        Formula(const Formula& f);
        bool operator==(const Formula& f) const;
        Formula& operator=(const Formula& f);
        Formula& operator=(const char str[]);
        friend std::istream& operator>>(std::istream& in, Formula& f);
        friend std::ostream& operator<<(std::ostream& out, const Formula& f);
};

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
    if ('^' == ch || '&' == ch || '|' == ch || '-' == ch || '<' == ch)
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

inline bool Formula::setVar()
{
    if (var <= maxVar)
        ++var;
    std::bitset<26> tmp(var);
    value = tmp;
}

inline bool Formula::getVar(char ch)
{
    std::vector<char>::iterator found = std::find(variable.begin(), variable.end(), ch);
    return value[found - variable.begin()];
}

#endif
