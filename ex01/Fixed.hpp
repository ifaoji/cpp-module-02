#pragma once

#ifndef FIXED_HPP_
#define FIXED_HPP_

#include <ostream>

class Fixed {
public:
  Fixed();
  Fixed(const int value);
  Fixed(const float value);
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(const int raw);

  float toFloat(void) const;
  int toInt(void) const;

private:
  static const int kFractionalBits = 8;

  int value_;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
