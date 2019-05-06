#include "CalcTest.hpp"

namespace {
    GTEST_TEST(CalcBasicCommandTest, handleZeroAndDecimalPointInput) {
        Calculator c = Calculator();
        ASSERT_EQ(c.getResult(), "0");
        c.makeInput(Calculator::Command::Zero);
        ASSERT_EQ(c.getResult(), "0");
        c.makeInput(Calculator::Command::Zero);
        ASSERT_EQ(c.getResult(), "0");
        c.makeInput(Calculator::Command::DecimalPoint);
        ASSERT_EQ(c.getResult(), "0.");
        c.makeInput(Calculator::Command::DecimalPoint);
        ASSERT_EQ(c.getResult(), "0.");
        c.makeInput(Calculator::Command::Zero);
        ASSERT_EQ(c.getResult(), "0.0");
        c.makeInput(Calculator::Command::Zero);
        ASSERT_EQ(c.getResult(), "0.00");
    }

    GTEST_TEST(CalcBasicCommandTest, handleClearAndDelInput) {
        Calculator c = Calculator();
        c.setInput("12.345");
        ASSERT_EQ(c.getResult(), "12.345");
        c.makeInput(Calculator::Command::Delete);
        ASSERT_EQ(c.getResult(), "12.34");
        c.makeInput(Calculator::Command::Delete);
        ASSERT_EQ(c.getResult(), "12.3");
        c.makeInput(Calculator::Command::Delete);
        ASSERT_EQ(c.getResult(), "12.");
        c.makeInput(Calculator::Command::Delete);
        ASSERT_EQ(c.getResult(), "12");
        c.makeInput(Calculator::Command::Clear);
        ASSERT_EQ(c.getResult(), "0");
        c.makeInput(Calculator::Command::Clear);
        ASSERT_EQ(c.getResult(), "0");
        c.makeInput(Calculator::Command::Delete);
        ASSERT_EQ(c.getResult(), "0");
        c.makeInput(Calculator::Command::One);
        ASSERT_EQ(c.getResult(), "1");
    }

    GTEST_TEST(CalcBasicCommandTest, handlePercentInput) {
        Calculator c = Calculator();
        ASSERT_EQ(c.getResult(), "0");
        c.makeInput(Calculator::Command::Percent);
        ASSERT_EQ(c.getResult(), "0");
        c.makeInput(Calculator::Command::DecimalPoint);
        ASSERT_EQ(c.getResult(), "0.");
        c.makeInput(Calculator::Command::Percent);
        ASSERT_EQ(c.getResult(), "0");
        c.setInput("1");
        ASSERT_EQ(c.getResult(), "1");
        c.makeInput(Calculator::Command::Percent);
        ASSERT_EQ(c.getResult(), "0.01");
        c.setInput("10");
        ASSERT_EQ(c.getResult(), "10");
        c.makeInput(Calculator::Command::Percent);
        ASSERT_EQ(c.getResult(), "0.1");
        c.setInput("200");
        ASSERT_EQ(c.getResult(), "200");
        c.makeInput(Calculator::Command::Percent);
        ASSERT_EQ(c.getResult(), "2");
        c.setInput("201");
        ASSERT_EQ(c.getResult(), "201");
        c.makeInput(Calculator::Command::Percent);
        ASSERT_EQ(c.getResult(), "2.01");
        c.setInput("15");
        ASSERT_EQ(c.getResult(), "15");
        c.makeInput(Calculator::Command::Percent);
        ASSERT_EQ(c.getResult(), "0.15");
        c.setInput("7652");
        ASSERT_EQ(c.getResult(), "7652");
        c.makeInput(Calculator::Command::Percent);
        ASSERT_EQ(c.getResult(), "76.52");
    }

    GTEST_TEST(CalcBasicCommandTest, handleNegation) {
        Calculator c = Calculator();
        ASSERT_EQ(c.getResult(), "0");
        c.makeInput(Calculator::Command::Negate);
        ASSERT_EQ(c.getResult(), "-0");
        c.makeInput(Calculator::Command::Clear);
        ASSERT_EQ(c.getResult(), "0");
        c.makeInput(Calculator::Command::Negate);
        ASSERT_EQ(c.getResult(), "-0");
        c.makeInput(Calculator::Command::Delete);
        ASSERT_EQ(c.getResult(), "0");
        c.makeInput(Calculator::Command::Negate);
        ASSERT_EQ(c.getResult(), "-0");
        c.makeInput(Calculator::Command::Negate);
        ASSERT_EQ(c.getResult(), "0");
        c.setInput("12345");
        ASSERT_EQ(c.getResult(), "12345");
        c.makeInput(Calculator::Command::Negate);
        ASSERT_EQ(c.getResult(), "-12345");
        c.makeInput(Calculator::Command::Percent);
        ASSERT_EQ(c.getResult(), "-123.45");
        c.makeInput(Calculator::Command::Negate);
        ASSERT_EQ(c.getResult(), "123.45");
    }

    GTEST_TEST(CalcBasicCommandTest, handleAddition) {
        Calculator c{};
        c.setInput("123");
        ASSERT_EQ(c.getResult(), "123");
        c.makeInput(Calculator::Command::Plus);
        ASSERT_EQ(c.getResult(), "0");
        c.setInput("666");
        ASSERT_EQ(c.getResult(), "666");
        c.makeInput(Calculator::Command::Eval);
        ASSERT_EQ(c.getResult(), "789");
        c.makeInput(Calculator::Command::Plus);
        ASSERT_EQ(c.getResult(), "0");
        c.setInput("-45.67");
        ASSERT_EQ(c.getResult(), "-45.67");
        c.makeInput(Calculator::Command::Eval);
        ASSERT_EQ(c.getResult(), "743.33");
    }

    GTEST_TEST(CalcBasicCommandTest, handleMultiplePlusInput) {
        Calculator c{};
        c.setInput("123");
        c.makeInput(Calculator::Command::Plus);
        c.setInput("234");
        c.makeInput(Calculator::Command::Plus);
        ASSERT_EQ(c.getResult(), "0");
        c.setInput("233");
        c.makeInput(Calculator::Command::Eval);
        ASSERT_EQ(std::stoi(c.getResult()), 123 + 234 + 233);
    }

    GTEST_TEST(CalcBasicCommandTest, testCaseForComplexInput) {
        Calculator c{};
        c.setInput("233");
        c.makeInput(Calculator::Command::Minus);
        c.setInput("234");
        c.makeInput(Calculator::Command::Multiply);
        c.setInput("3");
        c.makeInput(Calculator::Command::Plus);
        c.setInput("4");
        c.makeInput(Calculator::Command::DecimalPoint);
        c.makeInput(Calculator::Command::Five);
        c.makeInput(Calculator::Command::Eval);
        ASSERT_EQ(c.getResult(), "1.5");  // (233 - 234) * 3 + 4.5 == 1.5
    }

}