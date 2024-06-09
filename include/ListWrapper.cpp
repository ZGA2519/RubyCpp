#include "ListWrapper.h"
#include "StringWrapper.h"
#include "IntegerWrapper.h"
#include <sstream>

template <typename T>
String List<T>::join(const std::string& delimiter) const {
    std::stringstream ss;
    for (size_t i = 0; i < list.size(); ++i) {
        try {
            ss << std::any_cast<T>(list[i]);
        } catch (const std::bad_any_cast& e) {
            throw std::runtime_error("List::join() failed: " + std::string(e.what()));
        }
        if (i < list.size() - 1) {
            ss << delimiter;
        }
    }
    return String(ss.str());
}

// Explicit instantiation of List for supported types
template class List<String>;
template class List<Integer>;