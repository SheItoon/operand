#include "Operand.hpp"
#include "Register.hpp"
#include <iostream>
#include <map>

template<typename Key, typename Value>
Register<Key, Value>::Register(const size_t membmax)
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
bool Register<Key, Value>::setSize(const size_t membmax)
{
    if (!_locked_size) 
    {
        _membmax = membmax;
        return _locked_size = true;
    }
    return false;
}

template<typename Key, typename Value>
Value Register<Key, Value>::getValueAt(int const rhs) const
{
    size_t index = 0;

    if (rhs < 0)
        throw std::range_error("negative range");
    index = rhs;
    if (index <= _membmax - 1)
        if (_reg.contains(index) && _reg.at(index) != nullptr)
            return _reg.at(index);
    throw std::out_of_range("no member found");
}

template<typename Key, typename Value>
size_t Register<Key, Value>::getSize() const
{
    return _membmax;
}

template<typename Key, typename Value>
bool Register<Key, Value>::push(int const rhs)
{
    size_t index = 0;

    if (rhs < 0)
        throw std::range_error("negative range");
    index = rhs;
    if (index <= _membmax - 1)
    {
        _reg[index] = nullptr; // replace by stack.top()
        //stack.pop();
        return true;
    }
    throw std::out_of_range("out of boundaries");
}