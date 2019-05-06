#include "Calculator.hpp"

Calculator::Calculator() : inputs{"0", "0"}, op{Op::OpNone} {}
Calculator::~Calculator() = default;

void Calculator::makeInput(Calculator::Command command) {
    long double currentOperand = std::stold(inputs.first);
    long double previousOperand = std::stold(inputs.second);
    std::stringstream ss;
    switch (command) {
        case Command::Zero:
        case Command::One:
        case Command::Two:
        case Command::Three:
        case Command::Four:
        case Command::Five:
        case Command::Six:
        case Command::Seven:
        case Command::Eight:
        case Command::Nine:
            if (inputs.first == "0") {
                inputs.first[0] = char('0' + command);
            } else if (inputs.first == "-0") {
                inputs.first[1] = char('0' + command);
            } else {
                inputs.first += char('0' + command);
            }
            break;
        case Command::Plus:
        case Command::Minus:
        case Command::Multiply:
        case Command::Divide:
            if (op != Op::OpNone) {
                ss << eval_handler(previousOperand, currentOperand, op);
                inputs.first = ss.str();
            }
            op = static_cast<Op>(command - Command::Plus);
            inputs.second = inputs.first;
            inputs.first = "0";
            break;
        case Command::Eval:
            if (op != Op::OpNone) {
                ss << eval_handler(previousOperand, currentOperand, op);
                inputs.second = inputs.first;
                inputs.first = ss.str();
                op = Op::OpNone;
            }
            break;
        case Command::DecimalPoint:
            if (inputs.first.find('.') == std::string::npos) {
                inputs.first += '.';
            }
            break;
        case Command::Negate:
            ss << -currentOperand;
            inputs.first = ss.str();
            break;
        case Command::Percent:
            ss << currentOperand / 100.0L;
            inputs.first = ss.str();
            break;
        case Command::Delete:
            if (inputs.first == "0") {
                break;
            } else if (inputs.first == "-0") {
                inputs.first.erase(inputs.first.begin());
            } else if (inputs.first.size() == 1 || (inputs.first.size() == 2 && inputs.first[0] == '-')) {
                inputs.first.replace(inputs.first.end() - 1, inputs.first.end(), 1, '0');
            } else {
                inputs.first.pop_back();
            }
            break;
        case Command::Clear:
            inputs.first = "0";
            break;
        case Reset:
            inputs = {"0", "0"};
            op = Op::OpNone;
            break;
    }
}

std::string Calculator::getResult() const {
    return inputs.first;
}

Calculator::Op Calculator::getActiveOperator() const {
    return op;
}

#ifdef IS_DEBUGGING
void Calculator::setInput(std::string input) {
    std::swap(inputs.first, input);
}
#endif

long double Calculator::eval_handler(long double operandLeft, long double operandRight, Op operation) {
    switch (operation) {
        case Op::OpPlus:
            return operandLeft + operandRight;
        case Op::OpMinus:
            return operandLeft - operandRight;
        case Op::OpMultiply:
            return operandLeft * operandRight;
        case Op::OpDivide:
            return operandLeft / operandRight;
        case Op::OpNone:
            return operandRight;
    }
}