#include "safe_int.h"
#include <limits>
#include <string>
#include "divide_by_zero_exception.h"

SafeInt::SafeInt(int n) : value_(n) {}

SafeInt SafeInt::operator+(const SafeInt& x) const {
  std::string except = "Integer overflow occurs in ";
  except += std::to_string(value_);
  except += " + ";
  except += std::to_string(x.value_);
  if (value_ > 0 && x.value_ > 0) {
    if (value_ > std::numeric_limits<int>::max() - x.value_) {
          throw std::overflow_error(except);
    }
  } else if (value_ < 0 && x.value_ < 0) {
    if (value_ < std::numeric_limits<int>::min() - x.value_) {
          throw std::overflow_error(except);
    }
  }
  return SafeInt(value_ + x.value_);
}

SafeInt SafeInt::operator-(const SafeInt& x) const {
  std::string except = "Integer overflow occurs in ";
  except += std::to_string(value_);
  except += " - ";
  except += std::to_string(x.value_);
  if (value_ > 0 && x.value_ < 0) {
    if (value_ > std::numeric_limits<int>::max() + x.value_) {
        throw std::overflow_error(except);
    }
  } else if (value_ < 0 && x.value_ > 0) {
    if (value_ < std::numeric_limits<int>::min() + x.value_) {
        throw std::overflow_error(except);
    }
  }
  return SafeInt(value_ - x.value_);
}

SafeInt SafeInt::operator*(const SafeInt& x) const {
  std::string except = "Integer overflow occurs in ";
  except += std::to_string(value_);
  except += " * ";
  except += std::to_string(x.value_);
  if (value_ != 0) {
    if ((x.value_ > 0 && (value_ > std::numeric_limits<int>::max() / x.value_ ||
    value_ < std::numeric_limits<int>::min() / x.value_)) ||
        (x.value_ < 0 && (value_ > std::numeric_limits<int>::min() / x.value_ ||
    value_ < std::numeric_limits<int>::max() / x.value_))) {
      throw std::overflow_error(except);
    }
  }
  return SafeInt(value_ * x.value_);
}

SafeInt SafeInt::operator/(const SafeInt& x) const {
  if (x.value_ == 0) {
    std::string exception = "Divide-by-zero exception occurs in ";
    exception += std::to_string(value_);
    exception += "/0";
    throw DivideByZeroException(exception.c_str());
  }
  return SafeInt(value_ / x.value_);
}

SafeInt SafeInt::operator%(const SafeInt& x) const {
  if (x.value_ == 0) {
    std::string exception = "Divide-by-zero exception occurs in ";
    exception += std::to_string(value_);
    exception += "%0";
    throw DivideByZeroException(exception.c_str());
  }
  return SafeInt(value_ % x.value_);
}

int SafeInt::value() const {
  return value_;
}
