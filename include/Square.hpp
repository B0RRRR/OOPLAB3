#pragma once

#include "Figure.hpp"

namespace geometry {

class Square : public Figure {
public:
    Square();
    explicit Square(const Point& bl, long double side);

    Square(const Square& other);
    Square& operator=(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(Square&& other) noexcept;

    long double Area() const override;

    void ReadPoints(std::istream& is) override;
    void PrintPoints(std::ostream& os) const override;

    Figure* clone() const override;
};

}  // namespace geometry
