#pragma once

#include <string>

typedef enum eOperandType
{
    INT8,
    INT16/*,
    INT32,
    FLOAT,
    DOUBLE,
    BIGDECIMAL*/
} eOperandType;

/*
template<typename T> concept Reg =
requires {
    typename std::vector<T>;
    typename size_t;
};*/

class IOperand
{
public:
    virtual std::string const & toString() const = 0;
    virtual eOperandType getType() const = 0;
    virtual IOperand const * operator+(const IOperand &) const = 0;
    virtual ~IOperand() {}
};

template <typename T>
class Operand : public IOperand
{
    public:
        virtual std::string const &toString() const override;
        virtual eOperandType getType() const override;
        IOperand const * operator+(const IOperand &target) const override;/*
        IOperand const * operator-(const IOperand &target) const override;
        IOperand const * operator*(const IOperand &target) const override;
        IOperand const * operator/(const IOperand &target) const override;
        IOperand const * operator%(const IOperand &target) const override;*/
        Operand(eOperandType type, const std::string & value);
        ~Operand();

    protected:
        std::string value;
        eOperandType type;
};
template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;

class Int8 : public Operand<int8_t>
{
public:
    Int8(std::string const &value);
    ~Int8() {}
};

class Int16 : public Operand<int16_t>
{
public:
    Int16(std::string const &value);
    ~Int16() {}
};