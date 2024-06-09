#include "IntegerWrapper.h"
#include "StringWrapper.h"

// Implement the to_s method
String Integer::to_s() const {
    return String(std::to_string(value));
}
