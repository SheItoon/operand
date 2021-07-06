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

class IOperand
{
public:
    virtual std::string const & toString() const = 0;
    virtual eOperandType getType() const = 0;
    virtual IOperand const * operator+(const IOperand &) const = 0;
    virtual ~IOperand() {}
};

class AOperand : public IOperand
{
protected:
    std::string value;
    eOperandType type;
};

class Int8 : public AOperand
{
public:
    Int8(std::string const &value);
    ~Int8() {}
    std::string const &toString(void) const override { return this->value; }
    eOperandType getType(void) const override { return this->type; }
    IOperand const * operator+(const IOperand &rhs) const override;
};

class Int16 : public AOperand
{
public:
    Int16(std::string const &value);
    ~Int16() {}
    std::string const &toString(void) const override { return this->value; }
    eOperandType getType(void) const override { return this->type; }

    IOperand const * operator+(const IOperand &rhs) const override;
};

std::string enumToString(eOperandType t);