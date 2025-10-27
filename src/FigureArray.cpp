#include "FigureArray.hpp"
#include <iostream>

namespace geometry {

void FigureArray::Add(std::unique_ptr<Figure> fig) {
    figures_.push_back(std::move(fig));
}

void FigureArray::Remove(size_t index) {
    if (index < figures_.size()) {
        figures_.erase(figures_.begin() + index);
    }
}

void FigureArray::PrintAll(std::ostream& os) const {
    for (size_t i = 0; i < figures_.size(); ++i) {
        figures_[i]->PrintPoints(os);
        os << "Size:" << figures_[i]->Area() << "\n";
    }
}

long double FigureArray::TotalArea() const {
    long double total = 0;
    for (const auto& f : figures_) {
        total += f->Area();
    }
    return total;
}

size_t FigureArray::Size() const {
    return figures_.size();
}

}  // namespace geometry
