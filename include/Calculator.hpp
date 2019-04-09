#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <string>
#include <vector>
#include <sstream>

#include "CalcException.hpp"
#include "CalcCommand.hpp"

class Calculator {
private:
    std::vector<std::string> inputFieldList;
    char operation;

    void handleDigitInput(char digit);
    void handleOperatorInput(char operationType);
    void handleEval();
    void handleNegateInput();
    void handleDecimalPointInput();
    void handlePercentInput();
    void handleClearInput();
    void handleDelInput();
    void handleResetInput();

public:
    Calculator();
    ~Calculator();

    const std::string getCurrentInput() const noexcept;
    char getActiveOperator() const noexcept;
    void updateInputByCommand(const CalcCommand& cmd) noexcept;
    void updateInputByCommand(const CalcCommand&& cmd) noexcept;

#if CMAKE_BUILD_TYPE == DEBUG || DEBUG  // this member function is for debug only
    void setCurrentInput(const std::string& input);
#endif
};

#endif  // CALCULATOR_HPP