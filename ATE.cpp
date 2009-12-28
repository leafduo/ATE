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

#include <iostream>
#include <string>
#include <cassert>
#include "Formula.h"

using namespace std;

int main(int argc, const char* const argv[])
{
    Formula f1, f2;
    if (1 == argc) {
    cout << "Welcome \"Are they equivalent?\", would you want to know if they are equivalent?" << endl
        <<"Then please input two formulae. :)" << endl;
    cout << "Formula 1:";
    cin >> f1;
    cout << "Formula 2:";
    cin >> f2;
    } else if (3 == argc) {
        f1 = argv[1];
        f2 = argv[2];
    } else
        assert(false);
    if (f1 == f2)
        cout << "Yes, they are equivalent." << endl;
    else
        cout << "Sorry, they are not equivalent. :(" << endl;
    return 0;
}
