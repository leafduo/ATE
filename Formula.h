#ifndef FORMULA_H
#define FORMULA_H

#include <string>
#include <vector>
#include <queue>
#include <istream>
#include <ostream>

class Formula
{
    private:
        //inline bool isRPN() const;
        inline bool empty() const;
        bool evaluation() const;
        bool convertRPN();
        static inline bool assignment();
        static unsigned var;
        static const unsigned maxVar = 67108863u;
        std::string formula;
        std::queue<char, std::vector<char> > RPN;
    public:
        Formula();
        ~Formula();
        Formula(const std::string& str);
        Formula(const Formula& f);
        bool operator==(const Formula& f) const;
        Formula& operator=(const Formula& f);
        friend std::istream& operator>>(std::istream& in, Formula& f);
        friend std::ostream& operator<<(std::ostream& out, const Formula& f);
};

#endif
