#pragma once

#include "Figure.hpp"

namespace geometry {

class Rectangle : public Figure {
public:
    Rectangle() = default;
    Rectangle(const Point& origin, long double width, long double height);

    long double Area() const override;
    Figure* Clone() const override;

    void ReadPoints(std::istream& is) override;
    void PrintPoints(std::ostream& os) const override;
};

}  // namespace geometry
