#pragma once

#include "Figure.hpp"

namespace geometry {

class Square : public Figure {
public:
    Square() = default;
    Square(const Point& origin, long double side);

    long double Area() const override;
    Figure* Clone() const override;

    void ReadPoints(std::istream& is) override;
    void PrintPoints(std::ostream& os) const override;
};

}  // namespace geometry
