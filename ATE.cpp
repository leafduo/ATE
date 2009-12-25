#include <iostream>
#include <string>
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
    } else {
        f1 = argv[1];
        f2 = argv[2];
    }
    if (f1 == f2)
        cout << "Yes, they are equivalent." << endl;
    else
        cout << "Sorry, they are not equivalent. :(" << endl;
    return 0;
}
