#include "Swordman.h"
#include "ISerializable.h"
#include <fstream>

namespace SpecializedUnits {

    std::ostream& Swordman::Serialize(std::ostream& output) {
        Unit::Serialize(output);
        output << power << "\n";
        return output;
    }

    std::istream& Swordman::Deserialize(std::istream& input) {
        Unit::Deserialize(input);
        input >> power;
        input.ignore();
        return input;
    }

    void Swordman::Serialize(const std::string& path) {
        std::ofstream file(path);
        if (file.is_open()) {
            Serialize(file);
            file.close();
        }
    }

    void Swordman::Deserialize(const std::string& path) {
        std::ifstream file(path);
        if (file.is_open()) {
            Deserialize(file);
            file.close();
        }
    }

    void Swordman::Serialize() {
        std::cout << "Serializing Swordman: " << name << ", HP: " << HP << ", Power: " << power << std::endl;
    }

    void Swordman::Deserialize() {
        std::cout << "Deserializing Swordman: " << name << ", HP: " << HP << ", Power: " << power << std::endl;
    }
}
