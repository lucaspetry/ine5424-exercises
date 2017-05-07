#include <iostream>

/*
 * Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
 */

// Fibonacci(n)
template<long int n>
struct Fib {
  enum { RET = Fib<n - 1>::RET + Fib<n - 2>::RET };
};

// Fibonacci(1)
template<>
struct Fib<1> {
  enum { RET = 1 };
};

// Fibonacci(0)
template<>
struct Fib<0> {
  enum { RET = 0 };
};

int main() {
  std::cout << "26º Fib = " << Fib<26>::RET << std::endl;
  std::cout << "12º Fib = " << Fib<12>::RET << std::endl;
  std::cout << "4º Fib = " << Fib<4>::RET << std::endl;
  return 0;
}

