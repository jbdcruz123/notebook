
#include <stdexcept>
#include <iostream>
double square_root(double x) {
  if (x < 0.0) {
    throw std::invalid_argument("Input to square_root() must be non-negative.");
  }
  return std::sqrt(x);
}
int main() {
  try {
    double x = -1.0;
    double result = square_root(x);
    std::cout << "The square root of " << x << " is " << result << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return 0;
}
