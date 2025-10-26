#pragma once

#include <iostream>

namespace geometry {

struct Point {
    long double x;
    long double y;
};

inline std::istream& operator>>(std::istream& is, Point& p) {
    return is >> p.x >> p.y;
}

inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

}  // namespace geometry
