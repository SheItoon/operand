#pragma once

#include "Operand.hpp"
#include <vector>
#include <map>

template<typename Key, typename Value>
    requires std::is_arithmetic_v<Key> && std::is_pointer<Value>::value
class Register
{
    public:
        Register();
        Register(const size_t membmax);
        ~Register();
        bool setSize(const size_t membmax);
        Value getValueAt(int const) const;
        size_t getSize() const;
        bool push(int const);
    private:
        std::map<Key, Value> _reg;
        size_t _membmax;
        bool _locked_size;
};

template class Register<int, IOperand const *>;