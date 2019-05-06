#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <string>
#include <utility>
#include <sstream>

#if CMAKE_BUILD_TYPE == DEBUG || defined(DEBUG)
    #ifndef IS_DEBUGGING
    #define IS_DEBUGGING
    #endif
#endif

class Calculator {
public:
    enum Command {
        Zero,
        One,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Plus,
        Minus,
        Multiply,
        Divide,
        Eval,
        DecimalPoint,
        Negate,
        Percent,
        Delete,
        Clear,
        Reset
    };

    enum Op {
        OpPlus,
        OpMinus,
        OpMultiply,
        OpDivide,
        OpNone
    };

    Calculator();
    ~Calculator();

    void makeInput(Command command);
    std::string getResult() const;
    Op getActiveOperator() const;

#ifdef IS_DEBUGGING
    void setInput(std::string input);
#endif

private:
    std::pair<std::string, std::string> inputs;
    Op op;

    long double static eval_handler(long double operandLeft, long double operandRight, Op operation);
};

#endif  // CALCULATOR_HPP