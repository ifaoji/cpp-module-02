#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
  {
    Point a(0, 0);
    Point b(0, 2);
    Point c(2, 0);
    Point point(0.5f, 0.5f);

    std::cout << "1. (Inside) " << bsp(a, b, c, point) << std::endl;
  }

  {
    Point a(0, 0);
    Point b(0, 2);
    Point c(2, 0);
    Point point(0.0f, 0.0f);

    std::cout << "2. (On) " << bsp(a, b, c, point) << std::endl;
  }

  {
    Point a(0, 0);
    Point b(0, 2);
    Point c(2, 0);
    Point point(0.0f, -0.1f);

    std::cout << "3. (Out) " << bsp(a, b, c, point) << std::endl;
  }

  {
    Point a(0, 0);
    Point b(0, 2);
    Point c(2, 0);
    Point point(1.0f, 1.00390625f);

    std::cout << "4. (Out slightly) " << bsp(a, b, c, point) << std::endl;
  }

  {
    Point a(0, 0);
    Point b(0, 2);
    Point c(2, 0);
    Point point(0.00390625f, 0.00390625f);

    std::cout << "5. (In slightly) " << bsp(a, b, c, point) << std::endl;
  }

  {
    Point a(0.00390625f, 0.00390625f);
    Point b(0.0f, 2.00390625f);
    Point c(2.00390625f, 0.0f);
    Point point(0.00390625f, 0.00390625f);

    std::cout << "6. (In slightly) " << bsp(a, b, c, point) << std::endl;
  }

  {
    Point a(0.00390625f, 0.00390625f);
    Point b(0.0f, 2.00390625f);
    Point c(2.00390625f, 0.0f);
    Point point(0, 0);

    std::cout << "6. (Out slightly) " << bsp(a, b, c, point) << std::endl;
  }
}
