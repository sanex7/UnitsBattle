#include "Mage.h"
#include "ISerializable.h"
#include <fstream>

namespace SpecializedUnits {

    std::ostream& Mage::Serialize(std::ostream& output) {
        Unit::Serialize(output);
        output << mana << "\n";
        return output;
    }

    std::istream& Mage::Deserialize(std::istream& input) {
        Unit::Deserialize(input);
        input >> mana;
        input.ignore();
        return input;
    }

    void Mage::Serialize(const std::string& path) {
        std::ofstream file(path);
        if (file.is_open()) {
            Serialize(file);
            file.close();
        }
    }

    void Mage::Deserialize(const std::string& path) {
        std::ifstream file(path);
        if (file.is_open()) {
            Deserialize(file);
            file.close();
        }
    }

    void Mage::Serialize() {
        std::cout << "Serializing Mage: " << name << ", HP: " << HP << ", Mana: " << mana << std::endl;
    }

    void Mage::Deserialize() {
        std::cout << "Deserializing Mage: " << name << ", HP: " << HP << ", Mana: " << mana << std::endl;
    }
}
