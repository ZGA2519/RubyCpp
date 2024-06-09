#ifndef FLOAT_WRAPPER_H
#define FLOAT_WRAPPER_H

#include <iostream>
#include <stdexcept> // For std::invalid_argument
#include <cmath>

class Integer;
class String;

class Float {
private:
    double value;

public:
    // Default constructor
    Float() : value(0.0f) {}

    // Parameterized constructor
    Float(float v) : value(v) {}

    // Copy constructor
    Float(const Float& other) : value(other.value) {}

    // Assignment operator
    Float& operator=(const Float& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    // Arithmetic operators
    Float operator+(const Float& other) const {
        return Float(value + other.value);
    }

    Float operator-(const Float& other) const {
        return Float(value - other.value);
    }

    Float operator*(const Float& other) const {
        return Float(value * other.value);
    }

    Float operator/(const Float& other) const {
        if (other.value == 0.0f) {
            throw std::invalid_argument("Division by zero");
        }
        return Float(value / other.value);
    }

    // Compound assignment operators
    Float& operator+=(const Float& other) {
        value += other.value;
        return *this;
    }

    Float& operator-=(const Float& other) {
        value -= other.value;
        return *this;
    }

    Float& operator*=(const Float& other) {
        value *= other.value;
        return *this;
    }

    Float& operator/=(const Float& other) {
        if (other.value == 0.0f) {
            throw std::invalid_argument("Division by zero");
        }
        value /= other.value;
        return *this;
    }

    // Unary operators
    Float operator+() const {
        return *this;
    }

    Float operator-() const {
        return Float(-value);
    }

    // Comparison operators
    bool operator==(const Float& other) const {
        return value == other.value;
    }

    bool operator!=(const Float& other) const {
        return value != other.value;
    }

    bool operator<(const Float& other) const {
        return value < other.value;
    }

    bool operator>(const Float& other) const {
        return value > other.value;
    }

    bool operator<=(const Float& other) const {
        return value <= other.value;
    }

    bool operator>=(const Float& other) const {
        return value >= other.value;
    }

    // Conversion operator
    operator float() const {
        return value;
    }

    // Friend function for output
    friend std::ostream& operator<<(std::ostream& os, const Float& obj) {
        os << obj.value;
        return os;
    }

    // Friend function for input
    friend std::istream& operator>>(std::istream& is, Float& obj) {
        is >> obj.value;
        return is;
    }

    // Getter and setter
    float getValue() const {
        return value;
    }

    void setValue(float v) {
        value = v;
    }

    Integer to_i() const {
        return (int)value;
    }

    Integer ceil() const {
        return (int)std::ceil(value);
    }

    Integer floor() const {
        return (int)std::floor(value);
    }

    String to_s() const {
        return String(std::to_string(value));
    }
};

#endif // FLOAT_WRAPPER_H