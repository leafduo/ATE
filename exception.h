/*
   ATE -- Are They Equivalent?
   Copyright (C) 2009  leafduo.com

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


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
