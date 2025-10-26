#include <gtest/gtest.h>

#include "Square.hpp"
#include "Rectangle.hpp"
#include "Trapezoid.hpp"

namespace geometry {

TEST(FigureTest, SquareAreaAndCenter) {
    Square sq({0,0}, 4.0);
    EXPECT_DOUBLE_EQ(sq.Area(), 16.0);
    Point c = sq.Center();
    EXPECT_DOUBLE_EQ(c.x, 2.0);
    EXPECT_DOUBLE_EQ(c.y, 2.0);
}

TEST(FigureTest, SquareMoveAndRecalcCenter) {
    Square sq({1,1}, 2.0);
    EXPECT_DOUBLE_EQ(sq.Area(), 4.0);
    Point c = sq.Center();
    EXPECT_DOUBLE_EQ(c.x, 2.0);
    EXPECT_DOUBLE_EQ(c.y, 2.0);
}

TEST(FigureTest, SquareCloneIndependence) {
    Square sq({0,0}, 2.0);
    auto clone = std::unique_ptr<Figure>(sq.Clone());
    EXPECT_NE(clone.get(), &sq);
    EXPECT_DOUBLE_EQ(clone->Area(), sq.Area());
}

TEST(FigureTest, RectangleAreaAndCenter) {
    Rectangle r({0,0}, 3.0, 5.0);
    EXPECT_DOUBLE_EQ(r.Area(), 15.0);
    Point c = r.Center();
    EXPECT_DOUBLE_EQ(c.x, 1.5);
    EXPECT_DOUBLE_EQ(c.y, 2.5);
}

TEST(FigureTest, RectangleCloneAndIndependence) {
    Rectangle r({1,2}, 4.0, 2.0);
    auto copy = std::unique_ptr<Figure>(r.Clone());
    EXPECT_NE(copy.get(), &r);
    EXPECT_DOUBLE_EQ(copy->Area(), 8.0);
}

TEST(FigureTest, TrapezoidAreaAndCenter) {
    Trapezoid t({0,0}, {4,0}, {3,3}, {1,3});
    EXPECT_NEAR(t.Area(), 9.0, 1e-6);
    Point c = t.Center();
    EXPECT_DOUBLE_EQ(c.x, 2.0);
    EXPECT_DOUBLE_EQ(c.y, 1.5);
}

TEST(FigureTest, TrapezoidClone) {
    Trapezoid t({0,0},{2,0},{3,2},{1,2});
    auto copy = std::unique_ptr<Figure>(t.Clone());
    EXPECT_NE(copy.get(), &t);
    EXPECT_NEAR(copy->Area(), t.Area(), 1e-6);
}

TEST(FigureTest, TrapezoidInvalidCoordinatesProducesZeroArea) {
    Trapezoid t({0,0},{0,0},{0,0},{0,0});
    EXPECT_DOUBLE_EQ(t.Area(), 0.0);
}

TEST(FigureTest, PolymorphicBehavior) {
    std::unique_ptr<Figure> f1 = std::make_unique<Square>(Point{0,0}, 2.0);
    std::unique_ptr<Figure> f2 = std::make_unique<Rectangle>(Point{0,0}, 2.0, 3.0);
    std::unique_ptr<Figure> f3 = std::make_unique<Trapezoid>(
        Point{0,0}, Point{4,0}, Point{3,2}, Point{1,2});

    EXPECT_DOUBLE_EQ(f1->Area(), 4.0);
    EXPECT_DOUBLE_EQ(f2->Area(), 6.0);
    EXPECT_NEAR(f3->Area(), 6.0, 1e-6);
}

TEST(FigureTest, MultipleCentersDistinct) {
    Square s({0,0}, 2.0);
    Rectangle r({1,1}, 4.0, 2.0);
    Trapezoid t({0,0},{2,0},{3,2},{1,2});

    auto cs = s.Center();
    auto cr = r.Center();
    auto ct = t.Center();

    EXPECT_FALSE(cs.x == cr.x && cs.y == cr.y);
    EXPECT_FALSE(cr.x == ct.x && cr.y == ct.y);
}

}  // namespace geometry
