#ifndef OPERAND_H
#define OPERAND_H

#incldue "Op.h"

class Operand : public Op
{
    private:
        char data;
    public:
        inline char get() const;
        inline void set(char ch);
};


#endif
