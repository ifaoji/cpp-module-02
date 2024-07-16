#pragma once

#ifndef POINT_HPP_
#define POINT_HPP_

#include "Fixed.hpp"

class Point {
public:
  Point();
  Point(const float x, const float y);
  Point(const Point &other);

  ~Point();

  Point &operator=(const Point &rhs);

  const Fixed &x() const;
  const Fixed &y() const;

private:
  const Fixed x_;
  const Fixed y_;
};

bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif
