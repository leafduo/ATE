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
#include <fstream>
#include <string>
#include <stdexcept>

#include "Formula.h"

using namespace std;

int main(int argc, const char* const argv[])
{
    Formula f1, f2;
    try {
        if (1 == argc) {
            cout << "Welcome \"Are they equivalent?\", would you want to know if they are equivalent?" << endl
                <<"Then please input two formulae. :)" << endl;
            cout << "Formula 1:";
            cin >> f1;
            cout << "Formula 2:";
            cin >> f2;
        } else if (3 == argc) {
            if(!strcmp(argv[1], "-f")) {
                ifstream fin(argv[2]);
                try {
                    if (fin.fail())
                        throw runtime_error("Cannot open file!");
                } catch (runtime_error err) {
                    while (fin.fail()) {
                        cout << "Please check the file name and input again: ";
                        string fileName;
                        fin >> fileName;
                        fin.open(fileName.c_str());
                    }
                }
                fin >> f1;
                fin >> f2;
            } else {
                f1 = argv[1];
                f2 = argv[2];
            }
        } else
            throw runtime_error("Invalid agruments!");
    } catch (runtime_error err) {
        cerr << err.what() << endl
            << "Please check them and try again." << endl;
    }
    if (f1 == f2)
        cout << "Yes, they are equivalent." << endl;
    else
        cout << "Sorry, they are not equivalent. :(" << endl;
    return 0;
}
