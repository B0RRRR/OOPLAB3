#include "Trapezoid.hpp"

namespace geometry {

Trapezoid::Trapezoid() {
    v = VectorPoints(4);
}

Trapezoid::Trapezoid(const Point& bl, const Point& br, const Point& tr, const Point& tl) {
    v = VectorPoints(4);
    v.set(0, bl);
    v.set(1, br);
    v.set(2, tr);
    v.set(3, tl);
}

Trapezoid::Trapezoid(const Trapezoid& other) { v = other.v; }
Trapezoid& Trapezoid::operator=(const Trapezoid& other) { v = other.v; return *this; }

Trapezoid::Trapezoid(Trapezoid&& other) noexcept { v = std::move(other.v); }
Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept { v = std::move(other.v); return *this; }

long double Trapezoid::Area() const {
    return CalcArea(v);
}

void Trapezoid::ReadPoints(std::istream& is) {
    Figure::ReadPoints(is);
}

void Trapezoid::PrintPoints(std::ostream& os) const {
    Figure::PrintPoints(os);
}

Figure* Trapezoid::clone() const {
    return new Trapezoid(*this);
}

}  // namespace geometry
