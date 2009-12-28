#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

class Exception
{
    public:
        static void exit()
        {
            std::cout << "Sorry, you have input an invalid formula, please verify the formula and run me again. If you think this is a bug of me, please send an e-mail to the author -- leafduo@gmail.com. Thanks." << std::endl;
            std::exit(1);
        }
};

#endif
