#pragma once

#include "Figure.hpp"

namespace geometry {

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(const Point& bl, long double width, long double height);

    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;

    long double Area() const override;

    void ReadPoints(std::istream& is);
    void PrintPoints(std::ostream& os) const;

    Figure* clone() const override;
};

}  // namespace geometry
