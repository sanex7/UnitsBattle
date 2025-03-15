#include "Unit.h"
#include "ISerializable.h"
#include <fstream>

namespace BaseUnits {

    std::ostream& Unit::Serialize(std::ostream& output) {
        output << name << "\n" << HP << "\n";
        return output;
    }

    std::istream& Unit::Deserialize(std::istream& input) {
        std::getline(input, name);
        input >> HP;
        input.ignore();
        return input;
    }

    void Unit::Serialize(const std::string& path) {
        std::ofstream file(path);
        if (file.is_open()) {
            Serialize(file);
            file.close();
        }
    }

    void Unit::Deserialize(const std::string& path) {
        std::ifstream file(path);
        if (file.is_open()) {
            Deserialize(file);
            file.close();
        }
    }

    void Unit::Serialize() {
        std::cout << "Serializing Unit: " << name << ", HP: " << HP << std::endl;
    }

    void Unit::Deserialize() {
        std::cout << "Deserializing Unit: " << name << ", HP: " << HP << std::endl;
    }
}
