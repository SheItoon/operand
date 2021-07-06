#include "Operand.hpp"
#include <string>

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

//INT8 CLASS
Int8::Int8(std::string const &value)
{   
    try
    {
        throw value;
    }
    catch(std::string new_val)
    {
        this->value = new_val;
    }
    this->type = INT8;
}

IOperand const * Int8::operator+(const IOperand &rhs) const
{
    IOperand const *ret;

    switch (rhs.getType())
    {
        case INT8:
        {
            ret = new Int8(std::to_string(std::stod(this->value) + std::stod(rhs.toString())));
            break;
        }
        default:
        {
            ret = rhs.operator+(*this);
            break;
        }
    }

    return ret;
}

Int16::Int16(std::string const &value)
{
    this->value = value;
    this->type = INT16;
}

IOperand const * Int16::operator+(const IOperand &rhs) const
{
    IOperand *ret;

    switch (rhs.getType())
    {
        case INT8:
        case INT16:
        {
            ret = new Int16(std::to_string(int16_t(std::stod(this->value) + std::stod(rhs.toString()))));
            break;
        }
    }

    return ret;
}