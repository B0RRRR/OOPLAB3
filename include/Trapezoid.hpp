#pragma once
#include "Figure.hpp"

class Trapezoid : public Figure {
    Point vertices[4]; // Вершины трапеции в порядке обхода (нижний левый, нижний правый, верхний правый, верхний левый)
public:
    Trapezoid() = default;
    Trapezoid(const Point& bl, const Point& br, const Point& tr, const Point& tl);

    // Копирование и перемещение
    Trapezoid(const Trapezoid& other);
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid(Trapezoid&& other) noexcept;
    Trapezoid& operator=(Trapezoid&& other) noexcept;

    // Переопределённые методы Figure
    Point center() const override;
    double area() const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Figure* clone() const override;
};
