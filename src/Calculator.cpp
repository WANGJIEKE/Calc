#include "Calculator.hpp"

Calculator::Calculator() : inputFieldList({"0"}), operation('\0') {}

Calculator::~Calculator() = default;

const std::string Calculator::getCurrentInput() const noexcept {
    return inputFieldList.front();
}

char Calculator::getActiveOperator() const noexcept {
    return operation;
}

void Calculator::updateInputByCommand(const CalcCommand& cmd) noexcept {
    switch (cmd.getInputType()) {
        case Number:
            handleDigitInput(cmd.getSymbol());
            break;
        case Plus:
            handleOperatorInput('+');
            break;
        case Minus:
            handleOperatorInput('-');
            break;
        case Multiply:
            handleOperatorInput('*');
            break;
        case Divide:
            handleOperatorInput('/');
            break;
        case Eval:
            handleEval();
            break;
        case Negate:
            handleNegateInput();
            break;
        case DecimalPoint:
            handleDecimalPointInput();
            break;
        case Percent:
            handlePercentInput();
            break;
        case Clear:
            handleClearInput();
            break;
        case Del:
            handleDelInput();
            break;
        case Reset:
            handleResetInput();
            break;
    }
}

void Calculator::updateInputByCommand(const CalcCommand&& cmd) noexcept {
    updateInputByCommand(cmd);
}

#if CMAKE_BUILD_TYPE == DEBUG || defined(DEBUG)
void Calculator::setCurrentInput(const std::string& input) {
    inputFieldList.front() = input;
}
#endif

void Calculator::handleDigitInput(char digit) {
    std::string& currentInput = inputFieldList.front();
    if (currentInput.size() > 2) {
        currentInput += digit;
    } else if (currentInput.size() == 2) {
        if (currentInput[0] == '-' && currentInput[1] == '0') {
            currentInput[1] = digit;
        } else {
            currentInput += digit;
        }
    } else {
        if (currentInput[0] == '0' && digit != '0') {
            currentInput[0] = digit;
        } else {
            currentInput += digit;
        }
    }
}

void Calculator::handleOperatorInput(char operationType) {
    if (inputFieldList.size() >= 2) {
        handleEval();
    }
    inputFieldList.insert(inputFieldList.begin(), "0");
    operation = operationType;
}

void Calculator::handleEval() {
    std::stringstream ss;
    switch (operation) {
        case '+':
            ss << std::stod(inputFieldList.back()) + std::stod(inputFieldList.front());
            inputFieldList.front() = ss.str();
            break;
        case '-':
            ss << std::stod(inputFieldList.back()) - std::stod(inputFieldList.front());
            inputFieldList.front() = ss.str();
            break;
        case '*':
            ss << std::stod(inputFieldList.back()) * std::stod(inputFieldList.front());
            inputFieldList.front() = ss.str();
            break;
        case '/':
            ss << std::stod(inputFieldList.back()) / std::stod(inputFieldList.front());
            inputFieldList.front() = ss.str();
            break;
        default:
            return;
    }
    inputFieldList.pop_back();
    operation = '\0';
}

void Calculator::handleNegateInput() {
    if (inputFieldList.front()[0] == '-') {
        inputFieldList.front().erase(inputFieldList.front().begin());
    } else {
        inputFieldList.front() = '-' + inputFieldList.front();
    }
}

void Calculator::handleDecimalPointInput() {
    std::string& currentInput = inputFieldList.front();
    if (currentInput.find('.') == std::string::npos) {
        currentInput += '.';
    }
}

void Calculator::handlePercentInput() {
    std::string& currentInput = inputFieldList.front();
    if (currentInput == "0") return;
    if (currentInput == "0.") {
        currentInput.erase(currentInput.end() - 1);
        return;
    }
    std::stringstream ss;
    ss << std::stod(currentInput) / 100.0;
    currentInput = ss.str();
}

void Calculator::handleClearInput() {
    inputFieldList.front() = "0";
}

void Calculator::handleDelInput() {
    std::string& currentInput = inputFieldList.front();
    if (currentInput == "0") return;
    if (currentInput.size() == 2 && currentInput[0] == '-') {
        if (currentInput[1] == '0') currentInput.erase(currentInput.begin());
        else currentInput[1] = '0';
    }
    else if (currentInput.size() == 1) currentInput = "0";
    else currentInput.erase(currentInput.end() - 1);
}

void Calculator::handleResetInput() {
    operation = '\0';
    inputFieldList = {"0"};
}
