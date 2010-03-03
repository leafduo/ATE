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
        void process() const
        {
            std::cerr << what() << std::endl;
            if (!formula.empty())
                std::cerr << "The following formula is invalid: " << formula <<
                    std::endl;
            std::cerr << "Please check it and try again." << std::endl;
            std::exit(2);
        }
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
