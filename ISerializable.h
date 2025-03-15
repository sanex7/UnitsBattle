#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <iostream>
#include <fstream>
#include <string>

class ISerializable {
public:
    virtual std::ostream& Serialize(std::ostream& output) = 0;
    virtual std::istream& Deserialize(std::istream& input) = 0;
    virtual void Serialize(const std::string& path) = 0;
    virtual void Deserialize(const std::string& path) = 0;
    virtual void Serialize() = 0;
    virtual void Deserialize() = 0;

    virtual ~ISerializable() = default;
};

#endif
