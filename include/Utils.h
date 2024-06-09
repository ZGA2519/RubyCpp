#ifndef UTILS_H
#define UTILS_H

#include "StringWrapper.h"
#include <iostream>

// Implement gets function
String gets() {
    std::string input;
    std::getline(std::cin, input);
    return String(input);
}

#endif // UTILS_H
