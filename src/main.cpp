#include <iostream>
#include "Calculator.hpp"

const char* prompt = "Calc Interactive Command Line Interface\n"
                     "[0-9] single digit input\t[+-*/] corresponding operator\t[=] eval\n"
                     "[.] decimal point\t[d] delete\t[c] clear\t[r] reset calculator\n"
                     "[n] negate\t[%] divide by 100\n[?] show prompt\t[q] quit";

char OpToChar(Calculator::Op op) {
    switch (op) {
        case Calculator::Op::OpPlus:
            return '+';
        case Calculator::Op::OpMinus:
            return '-';
        case Calculator::Op::OpMultiply:
            return '*';
        case Calculator::Op::OpDivide:
            return '/';
        case Calculator::Op::OpNone:
            return '\0';
    }
}

void printCalculatorOutput(const Calculator& c) {
    std::cout << "text output: " << c.getResult()
              << " (with active operator " << OpToChar(c.getActiveOperator()) << ")" << std::endl;
}

int main() {
    Calculator c{};
    std::string input;
    std::cout << prompt << std::endl;
    std::cout << "input: " << std::flush;
    while (std::getline(std::cin, input)) {
        if (input.size() != 1) {
            std::cout << "invalid command; type '?' to show prompt" << std::endl;
            std::cout << "input: " << std::flush;
            continue;
        }
        switch (input[0]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                c.makeInput(static_cast<Calculator::Command>(input[0] - '0'));
                printCalculatorOutput(c);
                break;
            case '+':
                c.makeInput(Calculator::Command::Plus);
                printCalculatorOutput(c);
                break;
            case '-':
                c.makeInput(Calculator::Command::Minus);
                printCalculatorOutput(c);
                break;
            case '*':
                c.makeInput(Calculator::Command::Multiply);
                printCalculatorOutput(c);
                break;
            case '/':
                c.makeInput(Calculator::Command::Divide);
                printCalculatorOutput(c);
                break;
            case '=':
                c.makeInput(Calculator::Command::Eval);
                printCalculatorOutput(c);
                break;
            case '.':
                c.makeInput(Calculator::Command::DecimalPoint);
                printCalculatorOutput(c);
                break;
            case 'n':
                c.makeInput(Calculator::Command::Negate);
                printCalculatorOutput(c);
                break;
            case 'd':
                c.makeInput(Calculator::Command::Delete);
                printCalculatorOutput(c);
                break;
            case 'c':
                c.makeInput(Calculator::Command::Clear);
                printCalculatorOutput(c);
                break;
            case 'r':
                c.makeInput(Calculator::Command::Reset);
                printCalculatorOutput(c);
                break;
            case '%':
                c.makeInput(Calculator::Command::Percent);
                printCalculatorOutput(c);
                break;
            case 'q':
                return 0;
            case '?':
                std::cout << prompt << std::endl;
                break;
            default:
                std::cout << "invalid command; type '?' to show prompt" << std::endl;
        }
        std::cout << "input: " << std::flush;
    }
    return 0;
}