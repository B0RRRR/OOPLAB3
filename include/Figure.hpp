#pragma once
#include <iostream>
#include "VectorPoints.hpp"
#include "Point.hpp"

namespace geometry {

class Figure {
public:
    VectorPoints v;

    Figure() = default;
    virtual ~Figure() = default;
    

    long double CalcArea(const VectorPoints&) const;
    Point CalcCenter(const VectorPoints&) const;

    virtual void ReadPoints(std::istream& is);
    virtual void PrintPoints(std::ostream& os) const;

    virtual long double Area() const = 0;
    virtual Figure* clone() const = 0;

    friend bool operator==(const Figure&, const Figure&);
    friend bool operator!=(const Figure&, const Figure&);
};

std::istream& operator>>(std::istream&, Figure&);
std::ostream& operator<<(std::ostream&, const Figure&);

}  // namespace geometry
