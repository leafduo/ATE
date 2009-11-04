#ifndef FORMULA_H
#define FORMULA_H

#include <string>
#include <vector>
#include <list>
#include <istream>
#include <ostream>

class Formula
{
    private:
        //inline bool isRPN() const;
        inline bool empty() const;
        bool evaluation() const;
        bool convertRPN();
        static inline bool setVar();
        static inline bool getVar();
        static unsigned var;
        static const unsigned maxVar = 67108863u;
        std::string formula;
        std::list<char> RPN;
        std::list<char>::iterator PRNPointer;
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

#endif
