#ifndef INTEGER_WRAPPER_H
#define INTEGER_WRAPPER_H

#include <iostream>
#include <stdexcept> // For std::invalid_argument
#include <string>    // For std::to_string
#include "./StringWrapper.h"
// Forward declaration of String class
class String;


class Integer {
private:
    int value;

public:
    // Default constructor
    Integer() : value(0) {}

    // Parameterized constructor
    Integer(int v) : value(v) {}

    // Copy constructor
    Integer(const Integer& other) : value(other.value) {}

    // Assignment operator
    Integer& operator=(const Integer& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    // Arithmetic operators
    Integer operator+(const Integer& other) const {
        return Integer(value + other.value);
    }

    Integer operator-(const Integer& other) const {
        return Integer(value - other.value);
    }

    Integer operator*(const Integer& other) const {
        return Integer(value * other.value);
    }

    Integer operator/(const Integer& other) const {
        if (other.value == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return Integer(value / other.value);
    }

    // Compound assignment operators
    Integer& operator+=(const Integer& other) {
        value += other.value;
        return *this;
    }

    Integer& operator-=(const Integer& other) {
        value -= other.value;
        return *this;
    }

    Integer& operator*=(const Integer& other) {
        value *= other.value;
        return *this;
    }

    Integer& operator/=(const Integer& other) {
        if (other.value == 0) {
            throw std::invalid_argument("Division by zero");
        }
        value /= other.value;
        return *this;
    }

    // Unary operators
    Integer operator+() const {
        return *this;
    }

    Integer operator-() const {
        return Integer(-value);
    }

    // Comparison operators
    bool operator==(const Integer& other) const {
        return value == other.value;
    }

    bool operator!=(const Integer& other) const {
        return value != other.value;
    }

    bool operator<(const Integer& other) const {
        return value < other.value;
    }

    bool operator>(const Integer& other) const {
        return value > other.value;
    }

    bool operator<=(const Integer& other) const {
        return value <= other.value;
    }

    bool operator>=(const Integer& other) const {
        return value >= other.value;
    }

    // Conversion operator
    operator int() const {
        return value;
    }

    // Friend function for output
    friend std::ostream& operator<<(std::ostream& os, const Integer& obj) {
        os << obj.value;
        return os;
    }

    // Friend function for input
    friend std::istream& operator>>(std::istream& is, Integer& obj) {
        is >> obj.value;
        return is;
    }

    // Getter and setter
    int getValue() const {
        return value;
    }

    void setValue(int v) {
        value = v;
    }

    // Convert Integer to String
    String to_s() const;
};

#endif // INTEGER_WRAPPER_H
