#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
  float smallest = (++(Fixed())).toFloat();
  std::cout << smallest << std::endl;

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
    Point point(1.0f, smallest + 1);

    std::cout << "4. (Out slightly) " << bsp(a, b, c, point) << std::endl;
  }

  {
    Point a(0, 0);
    Point b(0, 2);
    Point c(2, 0);
    Point point(smallest, smallest);

    std::cout << "5. (In slightly) " << bsp(a, b, c, point) << std::endl;
  }

  {
    Point a(smallest, smallest);
    Point b(0.0f, smallest + 2);
    Point c(smallest + 2, 0.0f);
    Point point(smallest, smallest);

    std::cout << "6. (On slightly) " << bsp(a, b, c, point) << std::endl;
  }

  {
    Point a(smallest, smallest);
    Point b(0.0f, smallest + 2);
    Point c(smallest + 2, 0.0f);
    Point point(0, 0);

    std::cout << "7. (Out slightly) " << bsp(a, b, c, point) << std::endl;
  }

  {
    Point a(smallest, smallest);
    Point b(smallest, smallest + 2);
    Point c(smallest + 2, smallest);
    Point point(smallest * 2, smallest * 2);

    std::cout << "8. (In slightly) " << bsp(a, b, c, point) << std::endl;
  }

  {
    Point a(0, 0);
    Point b(0, 2);
    Point c(2, 0);
    Point point(0.0f, 1.0f);

    std::cout << "9. (On) " << bsp(a, b, c, point) << std::endl;
  }
}
