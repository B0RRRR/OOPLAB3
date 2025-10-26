#include "Rectangle.hpp"

namespace geometry {

Rectangle::Rectangle(const Point& origin, long double width, long double height) {
    points_ = {
        origin,
        {origin.x + width, origin.y},
        {origin.x + width, origin.y + height},
        {origin.x, origin.y + height}
    };
}

long double Rectangle::Area() const {
    return Figure::CalcArea(points_);
}

Figure* Rectangle::Clone() const {
    return new Rectangle(*this);
}

void Rectangle::ReadPoints(std::istream& is) {
    points_.resize(4);
    Figure::ReadPoints(is);
}

void Rectangle::PrintPoints(std::ostream& os) const {
    Figure::PrintPoints(os);
}

}  // namespace geometry
