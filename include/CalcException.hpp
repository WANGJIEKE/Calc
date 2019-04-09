#ifndef CALC_EXCEPTION_HPP
#define CALC_EXCEPTION_HPP

#include <exception>
#include <cstdlib>
#include <cstring>

class CalcException : public std::exception {
private:
    char *reason;
public:
    explicit CalcException(const char *reason);

    const char *what() const noexcept override;

    ~CalcException() override;
};

#endif  // CALC_EXCEPTION_HPP