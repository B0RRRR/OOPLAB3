#include <iostream>
#include <vector>
#include <memory>

#include "Figure.hpp"
#include "Square.hpp"
#include "Rectangle.hpp"
#include "Trapezoid.hpp"

int main() {
    std::vector<std::unique_ptr<geometry::Figure>> figures;

    while (true) {
        std::cout << "1. Добавить фигуру\n"
                  << "2. Показать все фигуры\n"
                  << "3. Показать общую площадь\n"
                  << "0. Выход\n";

        int choice;
        if (!(std::cin >> choice)) break;
        if (choice == 0) break;

        switch (choice) {
            case 1: {
                std::cout << "Выберите тип фигуры:\n1. Square\n2. Rectangle\n3. Trapezoid\n";
                int type; std::cin >> type;
                if (type == 1) {
                    long double x, y, side;
                    std::cout << "Введите x y и сторону: ";
                    std::cin >> x >> y >> side;
                    figures.push_back(std::make_unique<geometry::Square>(geometry::Point{x, y}, side));
                } else if (type == 2) {
                    long double x, y, w, h;
                    std::cout << "Введите x y width height: ";
                    std::cin >> x >> y >> w >> h;
                    figures.push_back(std::make_unique<geometry::Rectangle>(geometry::Point{x, y}, w, h));
                } else if (type == 3) {
                    long double x1,y1,x2,y2,x3,y3,x4,y4;
                    std::cout << "Введите координаты 4 точек (bl br tr tl): ";
                    std::cin >> x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
                    figures.push_back(std::make_unique<geometry::Trapezoid>(
                        geometry::Point{x1,y1}, geometry::Point{x2,y2}, geometry::Point{x3,y3}, geometry::Point{x4,y4}));
                } else {
                    std::cout << "Неверный выбор\n";
                }
                break;
            }
            case 2: {
                for (size_t i = 0; i < figures.size(); ++i) {
                    std::cout << i << ": ";
                    figures[i]->PrintPoints(std::cout);
                    std::cout << "Площадь: " << figures[i]->Area() << "\n";
                }
                break;
            }
            case 3: {
                long double total = 0;
                for (auto& f : figures) total += f->Area();
                std::cout << "Общая площадь: " << total << "\n";
                break;
            }
        }
    }

    return 0;
}
