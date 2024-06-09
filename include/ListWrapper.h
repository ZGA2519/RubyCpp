#ifndef LIST_WRAPPER_H
#define LIST_WRAPPER_H

#include <any>
#include <functional>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

// Forward declaration of String
class String;

template <typename T>
class List {
   private:
    std::vector<std::any> list;

   public:
    List() = default;
    List(std::initializer_list<std::any> init) : list(init) {}
    List(const std::vector<T>& vec) : list(vec.begin(), vec.end()) {}
    List(const List<T>& other) : list(other.list) {}
    List(List<T>&& other) noexcept : list(std::move(other.list)) {}

    List<T>& operator=(const List<T>& other) {
        if (this != &other) {
            list = other.list;
        }
        return *this;
    }

    List<T>& operator=(List<T>&& other) noexcept {
        if (this != &other) {
            list = std::move(other.list);
        }
        return *this;
    }

    void add(const T& element) { list.push_back(element); }

    void remove(const T& element) {
        for (auto it = list.begin(); it != list.end(); ++it) {
            try {
                T value = std::any_cast<T>(*it);
                if (value == element) {
                    list.erase(it);
                    return;
                }
            } catch (const std::bad_any_cast&) {
                // Ignore non-matching types
            }
        }
        throw std::out_of_range("Element not found in the list");
    }

    T& operator[](size_t index) {
        try {
            return std::any_cast<T&>(list.at(index));
        } catch (const std::bad_any_cast&) {
            throw std::out_of_range("Index out of range");
        }
    }

    const T& operator[](size_t index) const {
        try {
            return std::any_cast<const T&>(list.at(index));
        } catch (const std::bad_any_cast&) {
            throw std::out_of_range("Index out of range");
        }
    }

    size_t size() const { return list.size(); }
    void clear() { list.clear(); }
    bool empty() const { return list.empty(); }

    friend std::ostream& operator<<(std::ostream& os, const List<T>& lw) {
        os << "[";
        for (size_t i = 0; i < lw.list.size(); ++i) {
            try {
                T value = std::any_cast<T>(lw.list[i]);
                os << value;
            } catch (const std::bad_any_cast&) {
                os << "[unsupported type]";
            }
            if (i < lw.list.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    template <typename Func>
    auto map(Func func) -> List<typename std::invoke_result<Func, T>::type> {
        using ReturnType = typename std::invoke_result<Func, T>::type;
        std::vector<ReturnType> return_list;
        for (auto& element : list) {
            try {
                T value = std::any_cast<T>(element);
                return_list.push_back(func(value));
            } catch (const std::bad_any_cast&) {
                throw std::runtime_error("Failed to cast element during map operation.");
            }
        }
        return List<ReturnType>(return_list);
    }

    // Declaration of join, to be implemented in .cpp file
    String join(const std::string& delimiter = "") const;
};

#endif  // LIST_WRAPPER_H
