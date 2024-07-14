#include <iostream>

#include "Fixed.hpp"

int main(void) {
  {
    std::cout << "-----" << std::endl;
    std::cout << "Testing Comparison Operators" << std::endl;
    Fixed a(10);
    Fixed b(11);
    Fixed c = b;

    std::cout << a << " > " << b << " = " << (a > b) << std::endl;
    std::cout << a << " < " << b << " = " << (a < b) << std::endl;
    std::cout << c << " > " << b << " = " << (c > b) << std::endl;
    std::cout << c << " < " << b << " = " << (c < b) << std::endl;
    std::cout << a << " >= " << b << " = " << (a >= b) << std::endl;
    std::cout << a << " <= " << b << " = " << (a <= b) << std::endl;
    std::cout << c << " >= " << b << " = " << (c >= b) << std::endl;
    std::cout << c << " <= " << b << " = " << (c <= b) << std::endl;
    std::cout << a << " == " << b << " = " << (a == b) << std::endl;
    std::cout << a << " != " << b << " = " << (a != b) << std::endl;
    std::cout << c << " == " << b << " = " << (c == b) << std::endl;
    std::cout << c << " != " << b << " = " << (c != b) << std::endl;
    std::cout << "-----" << std::endl;
  }

  {
    std::cout << "-----" << std::endl;
    std::cout << "Testing Arithmetic Operators" << std::endl;
    Fixed a(5.23f);
    Fixed b(12.43f);
    Fixed c = b;

    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << a << " / " << b << " = " << (a / b) << std::endl;
    std::cout << "-----" << std::endl;
  }

  {
    std::cout << "-----" << std::endl;
    std::cout << "Testing Increment Operators" << std::endl;
    Fixed a;

    std::cout << a << "++ = " << a++ << " is now: " << a << std::endl;
    std::cout << a << "-- = " << a-- << " is now: " << a << std::endl;
    std::cout << "++" << a << " = " << ++a << " is now: " << a << std::endl;
    std::cout << "--" << a << " = " << --a << " is now: " << a << std::endl;
    std::cout << "-----" << std::endl;
  }

  {
    std::cout << "-----" << std::endl;
    std::cout << "Testing Min/Max Operators" << std::endl;
    const Fixed a(12.5f);
    const Fixed b(12.6f);

    std::cout << "a is: " << a << ", b is: " << b << std::endl;
    std::cout << "Max: " << Fixed::max(a, b) << std::endl;
    std::cout << "Min: " << Fixed::min(a, b) << std::endl;

    std::cout << "-----" << std::endl;
  }

  std::cout << "Tests from subject:" << std::endl;

  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max(a, b) << std::endl;

  std::cout << Fixed::max(a, b) + Fixed(1) << std::endl;

  return 0;
}
