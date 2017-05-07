#include <iostream>
#include <stdlib.h>

/*
 * Mult(a, b) = b + b + ... + b
 *                  a times
 */

// Mult(a, b)
template<int a, int b>
struct Mult {
  enum { A = a < 0 ? a - a - a : a,
         B = b < 0 ? b - b - b : b,
         RET = (a < 0 || b < 0) && (a >= 0 || b >= 0) ? -(Mult<A - 1, B>::RET + B) : Mult<A - 1, B>::RET + B };
};

// Mult(0, b)
template<int b>
struct Mult<0, b> {
  enum { RET = 0 };
};

// Mult(a, 0)
template<int a>
struct Mult<a, 0> {
  enum { RET = 0 };
};

int main() {
  std::cout << "4 * 6 = " << Mult<4, 6>::RET << std::endl;
  std::cout << "0 * 5 = " << Mult<0, 5>::RET << std::endl;
  std::cout << "-3 * 4 = " << Mult<-3, 4>::RET << std::endl;
  std::cout << "-4 * -5 = " << Mult<-4, -5>::RET << std::endl;
  std::cout << "0 * -6 = " << Mult<0, -6>::RET << std::endl;
  std::cout << "2 * -4 = " << Mult<2, -4>::RET << std::endl;
  return 0;
}

