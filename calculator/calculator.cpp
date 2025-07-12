// В этом файле определения функций.
// За основу возьмите решение предыдущей задачи.
#include "calculator.h"
#include <cmath>
#include <sstream>
#include <string>
#include <limits>

bool ReadNumber(Number& result) {
    std::string input;
    std::cin >> input;

    std::istringstream iss(input);
    if (!(iss >> result)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
    return true;
}

bool RunCalculatorCycle() {
    Number current = 0;
    Number memory = 0;
    bool memory_initialized = false;

    if (!ReadNumber(current)) {
        return false;
    }

    while (true) {
        std::string command;
        std::cin >> command;

        if (command == "+") {
            Number operand;
            if (!ReadNumber(operand)) return false;
            current += operand;
        }
        else if (command == "-") {
            Number operand;
            if (!ReadNumber(operand)) return false;
            current -= operand;
        }
        else if (command == "*") {
            Number operand;
            if (!ReadNumber(operand)) return false;
            current *= operand;
        }
        else if (command == "/") {
            Number operand;
            if (!ReadNumber(operand)) return false;
            if (operand == 0) {
                current = std::numeric_limits<Number>::infinity();
            }
            else {
                current /= operand;
            }
        }
        else if (command == "**") {
            Number operand;
            if (!ReadNumber(operand)) return false;
            current = std::pow(current, operand);
        }
        else if (command == "=") {
            std::cout << current << std::endl;
        }
        else if (command == ":") {
            if (!ReadNumber(current)) return false;
        }
        else if (command == "c") {
            current = 0;
        }
        else if (command == "s") {
            memory = current;
            memory_initialized = true;
        }
        else if (command == "l") {
            if (!memory_initialized) {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
            current = memory;
        }
        else if (command == "q") {
            return true;
        }
        else {
            std::cerr << "Error: Unknown token " << command << std::endl;
            return false;
        }
    }
}

