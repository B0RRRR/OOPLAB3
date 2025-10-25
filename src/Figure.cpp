#include "Figure.hpp"
#include <cmath>
#include <iostream>

namespace geometry {

long double Figure::CalcArea(const VectorPoints& t) const {
    long double res{0.0};
    for (size_t i = 0; i + 1 < t.len(); ++i) {
        res += t.get(i).x * t.get(i + 1).y;
        res -= t.get(i + 1).x * t.get(i).y;
    }
    res += t.get(t.len() - 1).x * t.get(0).y;
    res -= t.get(0).x * t.get(t.len() - 1).y;
    return std::abs(res / 2.0L);
}

Point Figure::CalcCenter(const VectorPoints& t) const {
    long double x = 0, y = 0;
    for (size_t i = 0; i < t.len(); ++i) {
        x += t.get(i).x;
        y += t.get(i).y;
    }
    return Point{ x / t.len(), y / t.len() };
}

void Figure::ReadPoints(std::istream& is) {
    for (size_t i = 0; i < v.len(); ++i) {
        Point p;
        is >> p.x >> p.y;
        v.set(i, p);
    }
}

void Figure::PrintPoints(std::ostream& os) const {
    for (size_t i = 0; i < v.len(); ++i) {
        Point p = v.get(i);
        os << "( " << p.x << ", " << p.y << ") ";
    }
}

std::istream& operator>>(std::istream& is, Figure& f) {
    f.ReadPoints(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& f) {
    f.PrintPoints(os);
    return os;
}

bool operator==(const Figure& a, const Figure& b) {
    if (a.v.len() != b.v.len()) return false;
    for (size_t i = 0; i < a.v.len(); ++i) {
        if (a.v.get(i).x != b.v.get(i).x || a.v.get(i).y != b.v.get(i).y)
            return false;
    }
    return true;
}

bool operator!=(const Figure& a, const Figure& b) {
    return !(a == b);
}

}  // namespace geometry
