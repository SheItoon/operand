#include "Operand.hpp"
#include "Register.hpp"
#include <iostream>

template<typename Key, typename Value>
Register<Key, Value>::Register(const int_fast8_t &&membmax)
{
    _membmax = membmax;
    _locked_size = true;
}

template<typename Key, typename Value>
Register<Key, Value>::Register()
{
    _membmax = 0;
    _locked_size = false;
}

template<typename Key, typename Value>
Register<Key, Value>::~Register()
{

}

template<typename Key, typename Value>
bool Register<Key, Value>::setSize(const int_fast8_t &&membmax)
{
    if (!_locked_size) 
    {
        _membmax = membmax;
        return _locked_size = true;
    }
    return false;
}

template<typename Key, typename Value>
Value const Register<Key, Value>::getValueAt(Value rhs) const
{
    int_fast8_t index = -1;

    index = std::stoi(rhs->toString());
    std::cout << "value is: " << index << std::endl;
    if (index >= 0 && index <= _membmax - 1)
        if (_reg.at(index) != nullptr)
            return _reg.at(index);
    return nullptr;
}

template<typename Key, typename Value>
size_t Register<Key, Value>::getSize() const
{
    return _membmax;
}

template<typename Key, typename Value>
bool Register<Key, Value>::push(Value rhs)
{
    int_fast8_t index = -1;

    index = std::stoi(rhs->toString());
    if (index >= 0 && index <= _membmax - 1)
        if (_reg[index] != nullptr) 
        {
            _reg[index] = rhs;
            return true;
        }
    return false;
}