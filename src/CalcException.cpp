#include "CalcException.hpp"

CalcException::CalcException(const char *reason) : reason(strdup(reason)) {}

const char *CalcException::what() const noexcept { return reason; }

CalcException::~CalcException() { free(reason); }
