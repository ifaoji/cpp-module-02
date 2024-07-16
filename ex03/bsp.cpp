#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point) {
  double denominator =
      (b.y().toFloat() - c.y().toFloat()) *
          (a.x().toFloat() - c.x().toFloat()) +
      (c.x().toFloat() - b.x().toFloat()) * (a.y().toFloat() - c.y().toFloat());

  double cross1 = ((b.y().toFloat() - c.y().toFloat()) *
                       (point.x().toFloat() - c.x().toFloat()) +
                   (c.x().toFloat() - b.x().toFloat()) *
                       (point.y().toFloat() - c.y().toFloat())) /
                  denominator;
  double cross2 = ((c.y().toFloat() - a.y().toFloat()) *
                       (point.x().toFloat() - c.x().toFloat()) +
                   (a.x().toFloat() - c.x().toFloat()) *
                       (point.y().toFloat() - c.y().toFloat())) /
                  denominator;
  double cross3 = 1 - cross1 - cross2;

  return (cross1 >= 0 && cross2 >= 0 && cross3 >= 0) ||
         (cross1 <= 0 && cross2 <= 0 && cross3 <= 0);
}
