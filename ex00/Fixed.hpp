#pragma once

#ifndef FIXED_HPP_
#define FIXED_HPP_

class Fixed {
public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(const int raw);

private:
  static const int kPointPosition = 8;

  int value_;
};

#endif
