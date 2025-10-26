#pragma once

#include <iostream>
#include <vector>

#include "Point.hpp"

namespace geometry {

class Figure {
public:
    Figure() = default;
    virtual ~Figure() = default;

    virtual void ReadPoints(std::istream& is);
    virtual void PrintPoints(std::ostream& os) const;

    virtual long double Area() const = 0;
    virtual Figure* Clone() const = 0;

    friend bool operator==(const Figure& a, const Figure& b);
    friend bool operator!=(const Figure& a, const Figure& b);

    Point Center() const;

protected:
    std::vector<Point> points_;

    static long double CalcArea(const std::vector<Point>& vertices);
    static Point CalcCenter(const std::vector<Point>& vertices);
};

std::istream& operator>>(std::istream& is, Figure& f);
std::ostream& operator<<(std::ostream& os, const Figure& f);

}  // namespace geometry
