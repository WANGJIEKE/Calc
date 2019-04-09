#include <iostream>

#include "Calculator.hpp"
#include "CalcException.hpp"
#include "CalcCommand.hpp"

const char* prompt = "Calc Interactive Command Line Interface\n"
                     "[0-9] single digit input\t[+-*/] corresponding operator\t[=] eval\n"
                     "[.] decimal point\t[d] delete\t[c] clear\t[r] reset calculator\n"
                     "[n] negate\t[%] divide by 100\n[?] show prompt\t[q] quit";

void printCalculatorOutput(const Calculator& c) {
    std::cout << "text output: " << c.getCurrentInput()
    << " (with active operator " << c.getActiveOperator() << ")" << std::endl;
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
                c.updateInputByCommand(CalcCommand::makeDigitInput(input[0]));
                printCalculatorOutput(c);
                break;
            case '+':
                c.updateInputByCommand(CalcCommand::makePlusInput());
                printCalculatorOutput(c);
                break;
            case '-':
                c.updateInputByCommand(CalcCommand::makeMinusInput());
                printCalculatorOutput(c);
                break;
            case '*':
                c.updateInputByCommand(CalcCommand::makeMultiplyInput());
                printCalculatorOutput(c);
                break;
            case '/':
                c.updateInputByCommand(CalcCommand::makeDiviseInput());
                printCalculatorOutput(c);
                break;
            case '=':
                c.updateInputByCommand(CalcCommand::makeEvalInput());
                printCalculatorOutput(c);
                break;
            case '%':
                c.updateInputByCommand(CalcCommand::makePercentInput());
                printCalculatorOutput(c);
                break;
            case 'n':
                c.updateInputByCommand(CalcCommand::makeNegateInput());
                printCalculatorOutput(c);
                break;
            case 'd':
                c.updateInputByCommand(CalcCommand::makeDelInput());
                printCalculatorOutput(c);
                break;
            case 'c':
                c.updateInputByCommand(CalcCommand::makeClearInput());
                printCalculatorOutput(c);
                break;
            case 'r':
                c.updateInputByCommand(CalcCommand::makeResetInput());
                printCalculatorOutput(c);
                break;
            case '.':
                c.updateInputByCommand(CalcCommand::makeDecimalPointInput());
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