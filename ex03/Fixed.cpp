#include <cmath>
#include <iostream>
#include <ostream>

#include "Fixed.hpp"

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a >= b)
    return a;

  return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a >= b)
    return a;

  return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a <= b)
    return a;

  return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a <= b)
    return a;

  return b;
}

Fixed::Fixed() : value_(0) {}

Fixed::Fixed(const int value) : value_(value << kFractionalBits) {}

Fixed::Fixed(const float value)
    : value_(roundf(value * (1 << kFractionalBits))) {}

Fixed::Fixed(const Fixed &other) { value_ = other.getRawBits(); }

Fixed &Fixed::operator=(const Fixed &rhs) {

  if (this == &rhs)
    return *this;

  value_ = rhs.getRawBits();

  return *this;
}

Fixed::~Fixed() {}

bool Fixed::operator>(const Fixed &rhs) const {
  return getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const {
  return getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
  return getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
  return getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const {
  return getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
  return getRawBits() != rhs.getRawBits();
}

Fixed Fixed::operator+(const Fixed &rhs) const {
  Fixed res;

  res.setRawBits(getRawBits() + rhs.getRawBits());

  return res;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
  Fixed res;

  res.setRawBits(getRawBits() - rhs.getRawBits());

  return res;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
  Fixed res;

  long long product = getRawBits() * rhs.getRawBits();
  product += 1LL << (kFractionalBits - 1);

  res.setRawBits(product >> kFractionalBits);

  return res;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
  Fixed res;

  long long dividend = (long long)getRawBits() << kFractionalBits;
  dividend += rhs.getRawBits() / 2;
  res.setRawBits(dividend / rhs.getRawBits());

  return res;
}

Fixed &Fixed::operator++() {
  setRawBits(getRawBits() + 1);

  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp = *this;

  setRawBits(getRawBits() + 1);

  return tmp;
}

Fixed &Fixed::operator--() {
  setRawBits(getRawBits() - 1);

  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp = *this;

  setRawBits(getRawBits() - 1);

  return tmp;
}

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
