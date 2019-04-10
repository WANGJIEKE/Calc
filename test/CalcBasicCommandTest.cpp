#include "CalcTest.hpp"

namespace {
    GTEST_TEST(CalcBasicCommandTest, handleZeroAndDecimalPointInput) {
        Calculator c = Calculator();
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeDigitInput('0'));
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeDigitInput('0'));
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeDecimalPointInput());
        ASSERT_EQ(c.getCurrentInput(), "0.");
        c.updateInputByCommand(CalcCommand::makeDecimalPointInput());
        ASSERT_EQ(c.getCurrentInput(), "0.");
        c.updateInputByCommand(CalcCommand::makeDigitInput('0'));
        ASSERT_EQ(c.getCurrentInput(), "0.0");
        c.updateInputByCommand(CalcCommand::makeDigitInput('0'));
        ASSERT_EQ(c.getCurrentInput(), "0.00");
    }

    GTEST_TEST(CalcBasicCommandTest, handleClearAndDelInput) {
        Calculator c = Calculator();
        c.setCurrentInput("12.345");
        ASSERT_EQ(c.getCurrentInput(), "12.345");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "12.34");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "12.3");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "12.");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "12");
        c.updateInputByCommand(CalcCommand::makeClearInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeClearInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeDigitInput('1'));
        ASSERT_EQ(c.getCurrentInput(), "1");
    }

    GTEST_TEST(CalcBasicCommandTest, handlePercentInput) {
        Calculator c = Calculator();
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makePercentInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeDecimalPointInput());
        ASSERT_EQ(c.getCurrentInput(), "0.");
        c.updateInputByCommand(CalcCommand::makePercentInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.setCurrentInput("1");
        ASSERT_EQ(c.getCurrentInput(), "1");
        c.updateInputByCommand(CalcCommand::makePercentInput());
        ASSERT_EQ(c.getCurrentInput(), "0.01");
        c.setCurrentInput("10");
        ASSERT_EQ(c.getCurrentInput(), "10");
        c.updateInputByCommand(CalcCommand::makePercentInput());
        ASSERT_EQ(c.getCurrentInput(), "0.1");
        c.setCurrentInput("200");
        ASSERT_EQ(c.getCurrentInput(), "200");
        c.updateInputByCommand(CalcCommand::makePercentInput());
        ASSERT_EQ(c.getCurrentInput(), "2");
        c.setCurrentInput("201");
        ASSERT_EQ(c.getCurrentInput(), "201");
        c.updateInputByCommand(CalcCommand::makePercentInput());
        ASSERT_EQ(c.getCurrentInput(), "2.01");
        c.setCurrentInput("15");
        ASSERT_EQ(c.getCurrentInput(), "15");
        c.updateInputByCommand(CalcCommand::makePercentInput());
        ASSERT_EQ(c.getCurrentInput(), "0.15");
        c.setCurrentInput("7652");
        ASSERT_EQ(c.getCurrentInput(), "7652");
        c.updateInputByCommand(CalcCommand::makePercentInput());
        ASSERT_EQ(c.getCurrentInput(), "76.52");
    }

    GTEST_TEST(CalcBasicCommandTest, handleNegation) {
        Calculator c = Calculator();
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeNegateInput());
        ASSERT_EQ(c.getCurrentInput(), "-0");
        c.updateInputByCommand(CalcCommand::makeClearInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeNegateInput());
        ASSERT_EQ(c.getCurrentInput(), "-0");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeNegateInput());
        ASSERT_EQ(c.getCurrentInput(), "-0");
        c.updateInputByCommand(CalcCommand::makeNegateInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.setCurrentInput("12345");
        ASSERT_EQ(c.getCurrentInput(), "12345");
        c.updateInputByCommand(CalcCommand::makeNegateInput());
        ASSERT_EQ(c.getCurrentInput(), "-12345");
        c.updateInputByCommand(CalcCommand::makePercentInput());
        ASSERT_EQ(c.getCurrentInput(), "-123.45");
        c.updateInputByCommand(CalcCommand::makeNegateInput());
        ASSERT_EQ(c.getCurrentInput(), "123.45");
    }

    GTEST_TEST(CalcBasicCommandTest, handleAddition) {
        Calculator c{};
        c.setCurrentInput("123");
        ASSERT_EQ(c.getCurrentInput(), "123");
        c.updateInputByCommand(CalcCommand::makePlusInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.setCurrentInput("666");
        ASSERT_EQ(c.getCurrentInput(), "666");
        c.updateInputByCommand(CalcCommand::makeEvalInput());
        ASSERT_EQ(c.getCurrentInput(), "789");
        c.updateInputByCommand(CalcCommand::makePlusInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.setCurrentInput("-45.67");
        ASSERT_EQ(c.getCurrentInput(), "-45.67");
        c.updateInputByCommand(CalcCommand::makeEvalInput());
        ASSERT_EQ(c.getCurrentInput(), "743.33");
    }

    GTEST_TEST(CalcBasicCommandTest, handleMultiplePlusInput) {
        Calculator c{};
        c.setCurrentInput("123");
        c.updateInputByCommand(CalcCommand::makePlusInput());
        c.setCurrentInput("234");
        c.updateInputByCommand(CalcCommand::makePlusInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.setCurrentInput("233");
        c.updateInputByCommand(CalcCommand::makeEvalInput());
        ASSERT_EQ(std::stoi(c.getCurrentInput()), 123 + 234 + 233);
    }

    GTEST_TEST(CalcBasicCommandTest, testCaseForComplexInput) {
        Calculator c{};
        c.setCurrentInput("233");
        c.updateInputByCommand(CalcCommand::makeMinusInput());
        c.setCurrentInput("234");
        c.updateInputByCommand(CalcCommand::makeMultiplyInput());
        c.setCurrentInput("3");
        c.updateInputByCommand(CalcCommand::makePlusInput());
        c.setCurrentInput("4");
        c.updateInputByCommand(CalcCommand::makeDecimalPointInput());
        c.updateInputByCommand(CalcCommand::makeDigitInput('5'));
        c.updateInputByCommand(CalcCommand::makeEvalInput());
        ASSERT_EQ(c.getCurrentInput(), "1.5");  // (233 - 234) * 3 + 4.5 == 1.5
    }

    GTEST_TEST(CalcBasicCommandTest, handleDivisionAndReset) {
        Calculator c{};
        c.setCurrentInput("24");
        c.updateInputByCommand(CalcCommand::makeDiviseInput());
        c.setCurrentInput("8");
        c.updateInputByCommand(CalcCommand::makeEvalInput());
        ASSERT_EQ(c.getCurrentInput(), "3");
        c.updateInputByCommand(CalcCommand::makeResetInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.setCurrentInput("1");
        c.updateInputByCommand(CalcCommand::makeDiviseInput());
        c.setCurrentInput("3");
        c.updateInputByCommand(CalcCommand::makeEvalInput());
        {
            std::stringstream ss;
            ss << 1.0 / 3.0;
            ASSERT_EQ(c.getCurrentInput(), ss.str());
        }
        c.updateInputByCommand(CalcCommand::makeResetInput());
        c.setCurrentInput("2");
        c.updateInputByCommand(CalcCommand::makeDiviseInput());
        c.updateInputByCommand(CalcCommand::makeEvalInput());
        {
            std::stringstream ss;
            ss << 2.0 / 0.0;
            ASSERT_EQ(c.getCurrentInput(), ss.str());
        }
    }

    GTEST_TEST(CalcBasicCommandTest, extraTestCase) {
        Calculator c{};
        c.updateInputByCommand(CalcCommand::makeEvalInput());
        c.updateInputByCommand(CalcCommand::makeEvalInput());
        c.updateInputByCommand(CalcCommand::makeEvalInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeResetInput());
        c.setCurrentInput("-0.3");
        c.updateInputByCommand(CalcCommand::makeNegateInput());
        ASSERT_EQ(c.getCurrentInput(), "0.3");
        c.setCurrentInput("-0.3");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "-0.");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "-0");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeResetInput());
        c.setCurrentInput("-13");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "-1");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "-0");
        c.updateInputByCommand(CalcCommand::makeDelInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
    }

    GTEST_TEST(CalcBasicCommandTest, extraTestCase2) {
        Calculator c{};
        c.updateInputByCommand(CalcCommand::makeMinusInput());
        ASSERT_EQ(c.getCurrentInput(), "0");
        c.updateInputByCommand(CalcCommand::makeNegateInput());
        ASSERT_EQ(c.getCurrentInput(), "-0");
        c.updateInputByCommand(CalcCommand::makeDigitInput('3'));
        ASSERT_EQ(c.getCurrentInput(), "-3");
    }

    GTEST_TEST(CalcBasicCommandTest, extraTestCase3) {
        {
            Calculator c{};
            c.updateInputByCommand(CalcCommand::makeDigitInput('1'));
            ASSERT_EQ(c.getCurrentInput(), "1");
            c.updateInputByCommand(CalcCommand::makeDigitInput('3'));
            ASSERT_EQ(c.getCurrentInput(), "13");
        }

        {
            Calculator c{};
            c.updateInputByCommand(CalcCommand::makeDigitInput('0'));
            ASSERT_EQ(c.getCurrentInput(), "0");
            c.updateInputByCommand(CalcCommand::makeDigitInput('0'));
            ASSERT_EQ(c.getCurrentInput(), "0");
        }
    }
}