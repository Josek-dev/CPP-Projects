#include <iostream>
#include <cmath>

class Geometric {
  public:
    Geometric(double a, double q): azero(a), q(q) {};
    double operator[](int n) const {
        return azero*pow(q,n);
    };
  private:
    double azero;
    double q;
};
int main() {
    const Geometric geometric(1., 0.5);
    std::cout << geometric[2] << std::endl;
}
