#include "Archer.h"
#include "ISerializable.h"
#include <fstream>

namespace SpecializedUnits {

    std::ostream& Archer::Serialize(std::ostream& output) {
        Unit::Serialize(output);
        output << arrows << "\n";
        return output;
    }

    std::istream& Archer::Deserialize(std::istream& input) {
        Unit::Deserialize(input);
        input >> arrows;
        input.ignore();
        return input;
    }

    void Archer::Serialize(const std::string& path) {
        std::ofstream file(path);
        if (file.is_open()) {
            Serialize(file);
            file.close();
        }
    }

    void Archer::Deserialize(const std::string& path) {
        std::ifstream file(path);
        if (file.is_open()) {
            Deserialize(file);
            file.close();
        }
    }

    void Archer::Serialize() {
        std::cout << "Serializing Archer: " << name << ", HP: " << HP << ", Arrows: " << arrows << std::endl;
    }

    void Archer::Deserialize() {
        std::cout << "Deserializing Archer: " << name << ", HP: " << HP << ", Arrows: " << arrows << std::endl;
    }
}
