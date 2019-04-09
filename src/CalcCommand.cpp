#include "CalcCommand.hpp"

CalcCommand::CalcCommand(CalcInstructionType inputType) : inputType(inputType), symbol('\0') {}
CalcCommand::CalcCommand(CalcInstructionType inputType, char symbol) : inputType(inputType), symbol(symbol) {}

CalcCommand CalcCommand::makeDigitInput(char symbol) {
    switch (symbol) {
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
            return {Number, symbol};
        default:
            throw CalcException("symbol passed into makeDigitInput() is not a digit");
    }
}

CalcCommand CalcCommand::makePlusInput() { return CalcCommand(Plus); }

CalcCommand CalcCommand::makeMinusInput() { return CalcCommand(Minus); }

CalcCommand CalcCommand::makeMultiplyInput() { return CalcCommand(Multiply); }

CalcCommand CalcCommand::makeDiviseInput() { return CalcCommand(Divide); }

CalcCommand CalcCommand::makeEvalInput() { return CalcCommand(Eval); }

CalcCommand CalcCommand::makeNegateInput() { return CalcCommand(Negate); }

CalcCommand CalcCommand::makePercentInput() { return CalcCommand(Percent); }

CalcCommand CalcCommand::makeDecimalPointInput() { return CalcCommand(DecimalPoint); }

CalcCommand CalcCommand::makeClearInput() { return CalcCommand(Clear); }

CalcCommand CalcCommand::makeDelInput() { return CalcCommand(Del); }

CalcCommand CalcCommand::makeResetInput() { return CalcCommand(Reset); }

CalcInstructionType CalcCommand::getInputType() const { return inputType; }

char CalcCommand::getSymbol() const {
    if (inputType != Number) throw CalcException("call getSymbol() on non-number command");
    return symbol;
}
