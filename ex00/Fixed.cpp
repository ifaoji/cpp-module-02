#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;

  value_ = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &rhs) {
  std::cout << "Copy assignment operator called" << std::endl;

  if (this == &rhs)
    return *this;

  value_ = rhs.getRawBits();

  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;

  return value_;
}

void Fixed::setRawBits(const int raw) {
  std::cout << "setRawBits member function called" << std::endl;

  value_ = raw;
}
