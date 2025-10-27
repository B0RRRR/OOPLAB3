#include "Trapezoid.hpp"

namespace geometry {

Trapezoid::Trapezoid(const Point& a, const Point& b, const Point& c, const Point& d) {
    points_ = {a, b, c, d};
}

long double Trapezoid::Area() const {
    return Figure::CalcArea(points_);
}

Figure* Trapezoid::Clone() const {
    return new Trapezoid(*this);
}

void Trapezoid::ReadPoints(std::istream& is) {
    points_.resize(4);
    Figure::ReadPoints(is);
}

void Trapezoid::PrintPoints(std::ostream& os) const {
    Figure::PrintPoints(os);
}

}  // namespace geometry
