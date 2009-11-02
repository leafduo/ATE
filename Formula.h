#ifndef FORMULA_H
#define FORMULA_H

#include <string>
#include <stack>
#include <istream>
#include <ostream>

class Formula
{
    private:
        //inline bool isRPN() const;
        inline bool empty() const;
        bool convertRPN();
        static inline bool assignment();
        static unsigned var = 0U;
        static const unsigned maxVar = pow(2, 26) - 1;
        bool evaluation() const;
        string formula;
        stack<char> RPN;
    public:
        Formula();
        ~Formula();
        Formula(string str);
        bool operator==(Formula f) const;
        Formula& operator=(Formula f);
        friend istream& operator>>(istream& in, Formula& f);
        friend ostream& operator<<(ostream& out, const Formula& f);
};

#endif
