#pragma once

#include "Operand.hpp"
#include <vector>
#include <map>

template<typename Key, typename Value>
class Register
{
    public:
        Register();
        Register(const int_fast8_t &&membmax);
        ~Register();
        bool setSize(const int_fast8_t &&membmax);
        Value const getValueAt(Value) const;
        size_t getSize() const;
        bool push(Value);
    private:
        std::map<Key, Value> _reg;
        int_fast8_t _membmax;
        bool _locked_size;
};
template class Register<int, IOperand const *>;