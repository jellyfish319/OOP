#include <string>
#include <limits>

class SafeInt {
 public:
  explicit SafeInt(int n);
  SafeInt operator+(const SafeInt& x) const;
  SafeInt operator-(const SafeInt& x) const;
  SafeInt operator*(const SafeInt& x) const;
  SafeInt operator/(const SafeInt& x) const;
  SafeInt operator%(const SafeInt& x) const;
  int value() const;
 private:
  int value_;
};

