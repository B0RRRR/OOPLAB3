#include "Square.hpp"

namespace geometry {

Square::Square(const Point& origin, long double side) {
    points_ = {
        origin,
        {origin.x + side, origin.y},
        {origin.x + side, origin.y + side},
        {origin.x, origin.y + side}
    };
}

long double Square::Area() const {
    return Figure::CalcArea(points_);
}

Figure* Square::Clone() const {
    return new Square(*this);
}

void Square::ReadPoints(std::istream& is) {
    points_.resize(4);
    Figure::ReadPoints(is);
}

void Square::PrintPoints(std::ostream& os) const {
    Figure::PrintPoints(os);
}

}  // namespace geometry
