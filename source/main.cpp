#include "Operand.hpp"
#include <iostream>

int main(void)
{
    IOperand *a = new Int8("50");
    IOperand *b = new Int16("30");
    IOperand const *result = a->operator+(*b);

    std::cout << "result" << std::endl
              << "type: " << enumToString(result->getType()) << std::endl
              << "value: " << result->toString() << std::endl;
    return 0;
}
