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


#include "Operator.h"
#include "Exception.h"

bool Operator::operator()(bool o1, bool o2) const
{
    if (XNOR == data)
        return o1 ^ o2;
    else if (IMPLICATION == data) {
        if (!o1)
            return true;
        else if (o2)
            return true;
        else
            return false;
    } else if (OR == data)
        return o1 || o2;
    else if (AND == data)
        return o1 && o2;
    else
        Exception::exit();
}

bool Operator::operator()(bool o) const
{
    if (NOT != data)
        Exception::exit();
    return !o;
}
