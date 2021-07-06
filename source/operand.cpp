#include "Operand.hpp"
#include <string>
#include <limits>
#include <iostream>

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
            try
            {
                ret = new Int8(std::to_string(std::stoll(this->value) + std::stoll(rhs.toString())));
                break;
            }
            catch(const std::out_of_range& e)
            {
                std::cerr << e.what() << std::endl;
            }
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
            try
            {
                ret = new Int16(std::to_string(std::stoll(this->value) + std::stoll(rhs.toString())));
                break;
            }
            catch(const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
    }
    return ret;
}