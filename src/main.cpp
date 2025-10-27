#include <iostream>
#include <memory>

#include "FigureArray.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Trapezoid.hpp"

int main() {
    geometry::FigureArray collection;

    while (true) {
        std::cout << "1. Add figure\n"
                  << "2. PrintAll Figures\n"
                  << "3. Total Square\n"
                  << "4. Delete Figure (index)\n"
                  << "0. Exit\n";

        int choice;
        if (!(std::cin >> choice)) break;
        if (choice == 0) break;

        switch (choice) {
            case 1: {
                std::cout << "Type figure:\n1. Square\n2. Rectangle\n3. Trapezoid\n";
                int type; std::cin >> type;
                if (type == 1) {
                    long double x, y, side;
                    std::cout << "x y and side: ";
                    std::cin >> x >> y >> side;
                    collection.Add(std::make_unique<geometry::Square>(geometry::Point{x, y}, side));
                } else if (type == 2) {
                    long double x, y, w, h;
                    std::cout << "x y width height: ";
                    std::cin >> x >> y >> w >> h;
                    collection.Add(std::make_unique<geometry::Rectangle>(geometry::Point{x, y}, w, h));
                } else if (type == 3) {
                    long double x1, y1, x2, y2, x3, y3, x4, y4;
                    std::cout << "Coords 4 points (bl br tr tl): ";
                    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
                    collection.Add(std::make_unique<geometry::Trapezoid>(
                        geometry::Point{x1, y1}, geometry::Point{x2, y2},
                        geometry::Point{x3, y3}, geometry::Point{x4, y4}));
                } else {
                    std::cout << "Invalid type!\n";
                }
                break;
            }
            case 2:
                collection.PrintAll(std::cout);
                break;

            case 3:
                std::cout << "Total square: " << collection.TotalArea() << "\n";
                break;

            case 4: {
                std::cout << "Index to delete: ";
                size_t idx;
                std::cin >> idx;
                collection.Remove(idx);
                break;
            }

            default:
                std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}
