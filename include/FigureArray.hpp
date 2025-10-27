#pragma once

#include <memory>
#include <vector>

#include "Figure.hpp"

namespace geometry {

class FigureArray {
public:
    void Add(std::unique_ptr<Figure> fig);
    void Remove(size_t index);
    void PrintAll(std::ostream& os) const;
    long double TotalArea() const;
    size_t Size() const;

private:
    std::vector<std::unique_ptr<Figure>> figures_;
};

}  // namespace geometry
