#include "Operand.hpp"
#include "Utils.hpp"
#include "Register.hpp"
#include <iostream>
#include <limits>

int main(void) try
{
    IOperand *a = new Int8("10");
    IOperand *b = new Int16("60");
    IOperand const *result = a->operator+(*b);
    Register<int, IOperand const *> reg(16);

    reg.push(a);
    if (result)
        std::cout << "result" << std::endl
                << "type: " << enumToString(result->getType()) << std::endl
                << "value: " << result->toString() << std::endl;
    std::cout << "register" << std::endl
            << "size: " << reg.getSize() << std::endl
            << "value at: " << reg.getValueAt(a)->toString() << std::endl;
    return 0;
} catch(std::exception const &e)
{ 
    std::cout << e.what() << std::endl;
    return 84;
}
