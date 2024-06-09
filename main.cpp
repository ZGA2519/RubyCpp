#include <iostream>

#include "include/TypeWrapper.h"

using namespace std;

int main() {
    String str = "1 2 3 4 5";
    cout << str.split().map([](String elm){ return elm.to_i() * elm.to_i();}).join(" ") << endl;
    // Float f = 1.5f;
    cout << String("1.24").to_f() << endl;
    cout << ((Integer)1).to_s() << endl;
    cout << gets().to_i() << endl;
    return 0;
}
