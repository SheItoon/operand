#include "Operand.hpp"
#include "Utils.hpp"
#include <string>
#include <limits>
#include <iostream>
#include <ranges>

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
            ret = new Int8(std::to_string(std::stoll(this->value) + std::stoll(rhs.toString())));
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
    std::string test;

    switch (rhs.getType())
    {
        case INT8:
        case INT16:
            int64_t test = std::stoll(this->value) + std::stoll(rhs.toString());
            if (test > std::numeric_limits<int16_t>::max())
                throw std::overflow_error(enumToString(this->type) + " overflow");
            if (test < std::numeric_limits<int16_t>::min())
                throw std::underflow_error(enumToString(this->type) + " underflow");
            ret = new Int16(std::to_string(test));
            break;
    }
    return ret;
}