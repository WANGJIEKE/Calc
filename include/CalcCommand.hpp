#ifndef CALC_COMMAND_HPP
#define CALC_COMMAND_HPP

#include "CalcException.hpp"

enum CalcInstructionType {
    Number, Plus, Minus, Multiply, Divide, Eval, Negate, Percent, DecimalPoint, Clear, Del, Reset
};

class CalcCommand {
private:
    CalcInstructionType inputType;
    char symbol;

    explicit CalcCommand(CalcInstructionType inputType);
    CalcCommand(CalcInstructionType inputType, char symbol);

public:
    static CalcCommand makeDigitInput(char symbol);
    static CalcCommand makePlusInput();
    static CalcCommand makeMinusInput();
    static CalcCommand makeMultiplyInput();
    static CalcCommand makeDiviseInput();
    static CalcCommand makeEvalInput();
    static CalcCommand makeNegateInput();
    static CalcCommand makePercentInput();
    static CalcCommand makeDecimalPointInput();
    static CalcCommand makeClearInput();
    static CalcCommand makeDelInput();
    static CalcCommand makeResetInput();

    CalcInstructionType getInputType() const;
    char getSymbol() const;
};

#endif  // CALC_COMMAND_HPP