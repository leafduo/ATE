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

#ifndef OPERATOR_H
#define OPERATOR_H

#include "exception.h"

#include <string>

#ifdef DEBUG
#include <iostream>
#endif

enum ENUM_OPERATOR
{
    PARE,
    XNOR,
    IMPLICATION,
    OR,
    AND,
    NOT,
};

class Operator
{
    private:
        ENUM_OPERATOR data;
    public:
        inline bool operator>(const Operator& o) const;
        inline bool operator<(const Operator& o) const;
        inline bool operator==(const Operator& o) const;
        inline bool operator!=(const Operator& o) const;
        inline Operator& operator=(const Operator& o);
        inline Operator& operator=(char ch);
        inline Operator();
        inline Operator(char ch);
        inline Operator(const Operator& o);
        inline friend std::string& operator+=(std::string & str, const Operator & op);
        bool operator()(bool o1, bool o2) const;
        bool operator()(bool o) const;
};

inline Operator::Operator(const Operator& o)
{
    *this = o;
}

inline bool Operator::operator>(const Operator& o) const
{
    return data > o.data;
}

inline bool Operator::operator<(const Operator& o) const
{
    return data < o.data;
}

inline bool Operator::operator==(const Operator& o) const
{
    return data == o.data;
}

inline bool Operator::operator!=(const Operator& o) const
{
    return data != o.data;
}

inline Operator& Operator::operator=(const Operator& o)
{
    data = o.data;
    return *this;
}

inline Operator& Operator::operator=(char ch)
{
    try {
        switch(ch) {
            default:
                throw formula_error("Invalid formula");
                break;
            case '!':
                data = NOT;
                break;
            case '&':
                data = AND;
                break;
            case '|':
                data = OR;
                break;
            case '-':
                data = IMPLICATION;
                break;
            case '^':
                data = XNOR;
                break;
            case '(':
                data = PARE;
                break;
        }
    } catch (formula_error err) {
        ;
    }
    return *this;
}

inline std::string& operator+=(std::string & str, const Operator & op)
{
    try {
        if (XNOR == op.data)
            return str += '^';
        else if (IMPLICATION == op.data)
            return str += '-';
        else if (OR == op.data)
            return str += '|';
        else if (AND == op.data)
            return str += '&';
        else if (NOT == op.data)
            return str += '!';
        else if (PARE == op.data)
            return str += '(';
        else
            throw formula_error("Invalid formula");
    } catch (formula_error err) {
        ;
    }
}

Operator::Operator(char ch)
{
    *this = ch;
}

#endif
