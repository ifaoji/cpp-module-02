#include <cmath>
#include <iostream>
#include <ostream>

#include "Fixed.hpp"

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : value_(value << kFractionalBits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : value_(roundf(value * (1 << kFractionalBits))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;

  value_ = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;

  if (this == &other)
    return *this;

  value_ = other.getRawBits();

  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const { return value_; }

void Fixed::setRawBits(const int raw) { value_ = raw; }

int Fixed::toInt(void) const { return getRawBits() >> kFractionalBits; }

float Fixed::toFloat(void) const {
  return ((float)getRawBits() / (1 << kFractionalBits));
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
  os << fixed.toFloat();

  return os;
}
