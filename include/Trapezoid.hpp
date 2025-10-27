#pragma once

#include "Figure.hpp"

namespace geometry {

class Trapezoid : public Figure {
public:
    Trapezoid() = default;
    Trapezoid(const Point& a, const Point& b, const Point& c, const Point& d);

    long double Area() const override;
    Figure* Clone() const override;

    void ReadPoints(std::istream& is) override;
    void PrintPoints(std::ostream& os) const override;
};

}  // namespace geometry
