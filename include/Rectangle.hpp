#pragma once
#include "Figure.hpp"

class Rectangle : public Figure {
    Point vertices[4];
public:
    Rectangle() = default;
    Rectangle(const Point& p, double width, double height);

    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;

    Point center() const override;
    double area() const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override;
};
