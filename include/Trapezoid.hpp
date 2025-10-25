#pragma once

#include "Figure.hpp"

namespace geometry {

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(const Point& bl, const Point& br, const Point& tr, const Point& tl);

    Trapezoid(const Trapezoid& other);
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    Trapezoid& operator=(Trapezoid&& other) noexcept;

    long double Area() const override;

    void ReadPoints(std::istream& is) override;
    void PrintPoints(std::ostream& os) const override;

    Figure* clone() const override;
};

}  // namespace geometry
