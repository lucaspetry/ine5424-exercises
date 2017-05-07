#include <iostream>

/*
 * GCD(a, b) = GCD(b, a%b)
 */

// GCD(a, b)
template<int a, int b>
struct GCD {
  enum { RET = GCD<b, a%b>::RET };
};

// GCD(a, 0)
template<int a>
struct GCD<a, 0> {
  enum { RET = a };
};

int main() {
  std::cout << "gcd(3, 7) = " << GCD<3, 7>::RET << std::endl;
  std::cout << "gcd(4, 12) = " << GCD<4, 12>::RET << std::endl;
  std::cout << "gcd(0, 13) = " << GCD<0, 13>::RET << std::endl;
  return 0;
}

