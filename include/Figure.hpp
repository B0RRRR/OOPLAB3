#pragma once
#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
};

class Figure {
public:
    virtual ~Figure() = default;

    virtual Point center() const = 0;
    virtual double area() const = 0;

    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    virtual Figure* clone() const = 0; // Для копирования через указатель

    friend std::ostream& operator<<(std::ostream& os, const Figure& f) {
        f.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& f) {
        f.read(is);
        return is;
    }
};
