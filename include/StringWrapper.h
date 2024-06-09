#ifndef STRING_WRAPPER_H
#define STRING_WRAPPER_H

#include <iostream>
#include <string>
#include "ListWrapper.h"

// Forward declarationd
class Integer;
template <typename T>
class List;

class String {
   private:
    std::string value;

   public:
    String() : value("") {}
    String(const std::string& v) : value(v) {}
    String(const char* v) : value(v) {}
    String(const String& other) : value(other.value) {}

    const std::string& getStdString() const { return value; }

    String& operator=(const String& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    String operator+(const String& other) const {
        return String(value + other.value);
    }

    String& operator+=(const String& other) {
        value += other.value;
        return *this;
    }

    bool operator==(const String& other) const { return value == other.value; }
    bool operator!=(const String& other) const { return value != other.value; }
    bool operator<(const String& other) const { return value < other.value; }
    bool operator>(const String& other) const { return value > other.value; }
    bool operator<=(const String& other) const { return value <= other.value; }
    bool operator>=(const String& other) const { return value >= other.value; }

    operator std::string() const { return value; }

    friend std::ostream& operator<<(std::ostream& os, const String& obj) {
        os << obj.value;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, String& obj) {
        is >> obj.value;
        return is;
    }

    const std::string& getValue() const { return value; }
    void setValue(const std::string& v) { value = v; }

    Integer to_i() const;

    // Declaration of split, to be implemented in .cpp file
    List<String> split(const std::string& delimiter = " ") const;
};

#endif  // STRING_WRAPPER_H
