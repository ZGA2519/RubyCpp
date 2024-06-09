#include "StringWrapper.h"
#include "IntegerWrapper.h"
#include "ListWrapper.h"

#include <stdexcept>
#include <string>

// Implement the to_i method
Integer String::to_i() const {
    try {
        return Integer(std::stoi(value));
    } catch (const std::invalid_argument&) {
        throw std::invalid_argument(
            "Invalid conversion from string to integer");
    }
}


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
