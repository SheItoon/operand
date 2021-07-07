#include "Operand.hpp"

std::string enumToString(eOperandType t)
{
    switch (t)
    {
    case INT8: return "INT8";
    case INT16: return "INT16";
        /*case INT32: return "INT32";
    case FLOAT: return "FLOAT";
    case DOUBLE: return "DOUBLE";
    case BIGDECIMAL: return "BIGDECIMAL";*/
    default: return "UNKNOWN";
    }
}