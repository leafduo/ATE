#include <iostream>
#include <string>
#include "Formula.h"

using namespace std;

int main(int argc, const char* const argv[])
{
    Formula f1, f2;
    if (1 == argc) {
    cout << "prompt:";
    cout << "f1:";
    cin >> f1;
    cout << "f2:";
    cin >> f2;
    } else {
        f1 = argv[1];
        f2 = argv[2];
    }
    if (f1 == f2)
        cout << "equivalent" << endl;
    else
        cout << "not equivalent" << endl;
    return 0;
}
