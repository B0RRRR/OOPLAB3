#include <cmath>

#include "Figure.hpp"

namespace geometry {

void Figure::ReadPoints(std::istream& is) {
    for (auto& p : points_) {
        is >> p;
    }
}

void Figure::PrintPoints(std::ostream& os) const {
    for (const auto& p : points_) {
        os << p << " ";
    }
}

long double Figure::CalcArea(const std::vector<Point>& vertices) {
    long double res = 0.0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i) {
        const Point& a = vertices[i];
        const Point& b = vertices[(i + 1) % n];
        res += a.x * b.y - a.y * b.x;
    }
    return std::abs(res / 2.0L);
}

Point Figure::Center() const {
    return CalcCenter(points_);
}

Point Figure::CalcCenter(const std::vector<Point>& vertices) {
    long double x_sum = 0.0, y_sum = 0.0;
    for (const auto& p : vertices) {
        x_sum += p.x;
        y_sum += p.y;
    }
    long double n = static_cast<long double>(vertices.size());
    return { x_sum / n, y_sum / n };
}

bool operator==(const Figure& a, const Figure& b) {
    if (a.points_.size() != b.points_.size()) return false;
    for (size_t i = 0; i < a.points_.size(); ++i)
        if (a.points_[i].x != b.points_[i].x || a.points_[i].y != b.points_[i].y)
            return false;
    return true;
}

bool operator!=(const Figure& a, const Figure& b) {
    return !(a == b);
}

std::istream& operator>>(std::istream& is, Figure& f) {
    f.ReadPoints(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& f) {
    f.PrintPoints(os);
    return os;
}

}  // namespace geometry
