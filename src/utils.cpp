#include "utils.h"
#include <iostream>

void printMessage(const std::string& message) {
    std::cout << "Message: " << message << std::endl;
}

int add(int a, int b) {
    return a + b;
}

double multiply(double a, double b) {
    return a * b;
} 