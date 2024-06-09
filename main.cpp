#include <iostream>

#include "include/TypeWrapper.h"

using namespace std;

int main() {
    String str = "1 2 3 4 5";
    cout << str.split().map([](String elm){ return elm.to_i() * elm.to_i();}).join(" ") << endl;
    return 0;
}
