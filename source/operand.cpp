//export module operand;
#include "Operand.hpp"
#include "Utils.hpp"
#include <string>
#include <limits>
#include <iostream>

//TEMPLATE
template <IsOperand T>
Operand<T>::Operand(eOperandType type, const std::string &value)
{
	this->type = type;
	this->value = value;
}

template <IsOperand T>
Operand<T>::~Operand()
{

}

template <IsOperand T>
std::string const &Operand<T>::toString(void) const
{
	return this->value;
}

template <IsOperand T>
eOperandType Operand<T>::getType(void) const
{
	return this->type;
}

template <IsOperand T>
IOperand const *Operand<T>::operator+(IOperand const &rhs) const
{
    IOperand *ret;
    std::string result = check_range<T>(this, &rhs);
    ret = new Operand<T>(this->getType(), result);
    /*
    if (this->getPrecision() + rhs.getPrecision() == 0)
        result = result.substr(0, result.find(".", 0));
    else if (this->getPrecision() > rhs.getPrecision()) 
        ret = vm.createOperand(this->getType(), result);
    else
        ret = vm.createOperand(rhs.getType(), result);*/
    return ret;
}

template <IsOperand T>
std::partial_ordering Operand<T>::operator<=>(IOperand const &rhs) const
{
    return std::stod(value) <=> std::stod(rhs.toString());
}

template <IsOperand T>
bool Operand<T>::operator==(IOperand const &rhs) const
{
    return std::stod(value) == std::stod(rhs.toString());
}

//INT8 CLASS
Int8::Int8(std::string const &value): Operand(INT8, value)
{
}

/*
IOperand const * Int8::operator+(const IOperand &rhs) const
{
    IOperand const *ret;

    switch (rhs.getType())
    {
        case INT8:
            ret = new Int8(check_range<int8_t>(this, &(rhs)));
            break;
        default:
            ret = rhs.operator+(*this);
            break;
    }
    return ret;
}*/

Int16::Int16(std::string const &value): Operand(INT16, value)
{
}

/*
IOperand const * Int16::operator+(const IOperand &rhs) const
{
    IOperand *ret;

    switch (rhs.getType())
    {
        case INT8:
        case INT16:
            ret = new Int16(check_range<int16_t>(this, &(rhs)));
            break;
    }
    return ret;
}*/