#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <stdexcept>
#include <string>

class formula_error: public std::logic_error
{
    private:
        std::string formula;
    public:
        const std::string & show()
        {
            return formula;
        }
        explicit formula_error(const std::string& what_arg)
            :logic_error(what_arg)
        { }
        explicit formula_error(const std::string& what_arg, const std::string& f)
            :logic_error(what_arg), formula(f)
        { }
        ~formula_error() throw()
        { }
};

#endif
