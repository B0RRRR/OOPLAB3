#include "Square.hpp"

namespace geometry {

Square::Square() {
    v = VectorPoints(4);
}

Square::Square(const Point& bl, long double side) {
    v = VectorPoints(4);
    v.set(0, bl);
    v.set(1, {bl.x + side, bl.y});
    v.set(2, {bl.x + side, bl.y + side});
    v.set(3, {bl.x, bl.y + side});
}

Square::Square(const Square& other) { v = other.v; }
Square& Square::operator=(const Square& other) { v = other.v; return *this; }

Square::Square(Square&& other) noexcept { v = std::move(other.v); }
Square& Square::operator=(Square&& other) noexcept { v = std::move(other.v); return *this; }

long double Square::Area() const {
    return CalcArea(v);
}

void Square::ReadPoints(std::istream& is) {
    Figure::ReadPoints(is);
}

void Square::PrintPoints(std::ostream& os) const {
    Figure::PrintPoints(os);
}

Figure* Square::clone() const {
    return new Square(*this);
}

}  // namespace geometry
