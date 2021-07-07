#pragma once

#include "Operand.hpp"
#include <string>
#include <iostream>

std::string enumToString(eOperandType t);
template <class T, class A>
std::string check_range(A const *a, A const *b);

template <class T, class A>
std::string check_range(A const *a, A const *b)
{
    int64_t const test = std::stoll(a->toString()) + std::stoll(b->toString());
    if (test > std::numeric_limits<T>::max())
        throw std::overflow_error(enumToString(a->getType()) + " overflow");
    if (test < std::numeric_limits<T>::min())
        throw std::underflow_error(enumToString(a->getType()) + " underflow");
    return std::to_string(test);
}