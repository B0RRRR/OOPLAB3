#pragma once
#include "Figure.hpp"

class Square : public Figure {
    Point vertices[4];
public:
    Square() = default;
    Square(const Point& p, double side);

    Square(const Square& other);
    Square& operator=(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(Square&& other) noexcept;

    Point center() const override;
    double area() const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override;
};
