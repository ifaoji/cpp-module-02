#include "Point.hpp"

Point::Point() : x_(0), y_(0) {}

Point::Point(const float x, const float y) : x_(x), y_(y) {}

Point::Point(const Point &other) : x_(other.x()), y_(other.y()) {}

Point::~Point() {}

Point &Point::operator=(const Point &rhs) {
  if (this == &rhs)
    return *this;

  // Commented out since this is undefined behaviour
  // const_cast<Fixed &>(x_) = rhs.x_;
  // const_cast<Fixed &>(y_) = rhs.y_;

  return *this;
}

const Fixed &Point::x() const { return x_; }

const Fixed &Point::y() const { return y_; }
