#include "StringWrapper.h"

#include <stdexcept>
#include <string>

#include "IntegerWrapper.h"
#include "FloatWrapper.h"

#include "ListWrapper.h"

// Implement the to_i method
Integer String::to_i() const {
    try {
        return Integer(std::stoi(value));
    } catch (const std::invalid_argument&) {
        throw std::invalid_argument(
            "Invalid conversion from string to integer");
    }
}

// Implement the split method
List<String> String::split(const std::string& delimiter) const {
    List<String> result;
    size_t pos = 0;
    size_t found;

    while ((found = value.find(delimiter, pos)) != std::string::npos) {
        result.add(value.substr(pos, found - pos));
        pos = found + delimiter.length();
    }

    // Add the last segment if it's not empty
    if (pos < value.length()) {
        result.add(value.substr(pos));
    }

    return result;
}

// Implement the to_f method
Float String::to_f() const { return Float(std::stof(value)); }
