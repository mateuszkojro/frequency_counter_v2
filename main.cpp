#include <iostream>

int add(int z) {
    return z + 2;
}

void func(int (*tranformer)(int) = add) {
    std::cout << tranformer(2) << std::endl;
}

int main() {
    func();
    func([](int x) { return x * 7; });
    return 0;
}
