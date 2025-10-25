#pragma once

#include <vector>
#include "Point.hpp"

namespace geometry {

class VectorPoints {
    std::vector<Point> points;
public:
    VectorPoints() = default;
    explicit VectorPoints(size_t n) : points(n) {}

    void set(size_t i, const Point& p) { points[i] = p; }
    Point get(size_t i) const { return points[i]; }
    size_t len() const { return points.size(); }

    void push_back(const Point& p) { points.push_back(p); }
};

}  // namespace geometry
