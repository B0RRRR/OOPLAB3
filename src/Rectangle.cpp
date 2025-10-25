#include "Rectangle.hpp"

namespace geometry {

Rectangle::Rectangle() {
    v = VectorPoints(4);
}

Rectangle::Rectangle(const Point& bl, long double width, long double height) {
    v = VectorPoints(4);
    v.set(0, bl);
    v.set(1, {bl.x + width, bl.y});
    v.set(2, {bl.x + width, bl.y + height});
    v.set(3, {bl.x, bl.y + height});
}

Rectangle::Rectangle(const Rectangle& other) { v = other.v; }
Rectangle& Rectangle::operator=(const Rectangle& other) { v = other.v; return *this; }

Rectangle::Rectangle(Rectangle&& other) noexcept { v = std::move(other.v); }
Rectangle& Rectangle::operator=(Rectangle&& other) noexcept { v = std::move(other.v); return *this; }

long double Rectangle::Area() const {
    return CalcArea(v);
}

void Rectangle::ReadPoints(std::istream& is) {
    Figure::ReadPoints(is);
}

void Rectangle::PrintPoints(std::ostream& os) const {
    Figure::PrintPoints(os);
}

Figure* Rectangle::clone() const {
    return new Rectangle(*this);
}

}  // namespace geometry
