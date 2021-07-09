#include "Operand.hpp"
#include "Utils.hpp"
#include "Register.hpp"
#include <iostream>
#include <limits>
#include <stack>

int main(void) try
{
    IOperand *a = new Int16("45");
    IOperand *b = new Int16("60");
    IOperand const *result = a->operator+(*b);
    Register<int, IOperand const *> reg(16);
    std::stack<IOperand const *>stack;

    std::cout << (*a <= *b) << std::endl;
    //reg.push(a);
    //auto res = reg.getValueAt(10);
    if (result)
        std::cout << "result" << std::endl
                << "type: " << enumToString(result->getType()) << std::endl
                << "value: " << result->toString() << std::endl;
    /*if (res)
        std::cout << "register" << std::endl
                << "size: " << reg.getSize() << std::endl
                << "value at " << res->toString() << ": " << enumToString(res->getType()) + " " << res->toString() << std::endl;*/
    delete a;
    delete b;
    delete result;
    return 0;
} catch(std::exception const &e)
{ 
    std::cout << e.what() << std::endl;
    return 84;
}
