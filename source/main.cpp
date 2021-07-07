#include "Operand.hpp"
#include <iostream>
#include <limits>

int main(void) try
{
    IOperand *a = new Int8("1");
    IOperand *b = new Int16(std::to_string(std::numeric_limits<int16_t>::max()));
    IOperand const *result = a->operator+(*b);

    if (result)
        std::cout << "result" << std::endl
                << "type: " << enumToString(result->getType()) << std::endl
                << "value: " << result->toString() << std::endl;
    return 0;
} catch(std::exception const &e)
{ 
    std::cout << e.what() << std::endl;
    return 1;
}
