#include "Operand.hpp"
#include "Utils.hpp"
#include <string>
#include <limits>
#include <iostream>

//INT8 CLASS
Int8::Int8(std::string const &value)
{
    this->value = value;
    this->type = INT8;
}

IOperand const * Int8::operator+(const IOperand &rhs) const
{
    IOperand const *ret;

    switch (rhs.getType())
    {
        case INT8:
            ret = new Int8(check_range<int8_t, IOperand>(this, &(rhs)));
            break;
        default:
            ret = rhs.operator+(*this);
            break;
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
            ret = new Int16(check_range<int16_t, IOperand>(this, &(rhs)));
            break;
    }
    return ret;
}