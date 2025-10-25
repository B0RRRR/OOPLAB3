#include <gtest/gtest.h>

#include "Square.hpp"
#include "Rectangle.hpp"
#include "Trapezoid.hpp"

TEST(FigureTest, SquareAreaAndCenter) {
    geometry::Square sq({0,0}, 4.0);
    EXPECT_DOUBLE_EQ(sq.Area(), 16.0);

    geometry::Point c = sq.CalcCenter(sq.v);
    EXPECT_DOUBLE_EQ(c.x, 2.0);
    EXPECT_DOUBLE_EQ(c.y, 2.0);
}

TEST(FigureTest, SquareClone) {
    geometry::Square sq({1,1}, 3.0);
    geometry::Figure* f = sq.clone();
    geometry::Square* sq_clone = dynamic_cast<geometry::Square*>(f);
    ASSERT_NE(sq_clone, nullptr);
    EXPECT_DOUBLE_EQ(sq_clone->Area(), 9.0);
    delete f;
}

TEST(FigureTest, RectangleAreaAndCenter) {
    geometry::Rectangle r({0,0}, 3.0, 5.0);
    EXPECT_DOUBLE_EQ(r.Area(), 15.0);

    geometry::Point c = r.CalcCenter(r.v);
    EXPECT_DOUBLE_EQ(c.x, 1.5);
    EXPECT_DOUBLE_EQ(c.y, 2.5);
}

TEST(FigureTest, RectangleClone) {
    geometry::Rectangle r({1,1}, 2.0, 4.0);
    geometry::Figure* f = r.clone();
    geometry::Rectangle* r_clone = dynamic_cast<geometry::Rectangle*>(f);
    ASSERT_NE(r_clone, nullptr);
    EXPECT_DOUBLE_EQ(r_clone->Area(), 8.0);
    delete f;
}

TEST(FigureTest, TrapezoidAreaAndCenter) {
    geometry::Trapezoid t({0,0},{4,0},{3,3},{1,3});
    double area = t.Area();
    EXPECT_NEAR(area, 9.0, 1e-6);

    geometry::Point c = t.CalcCenter(t.v);
    EXPECT_DOUBLE_EQ(c.x, 2.0);
    EXPECT_DOUBLE_EQ(c.y, 1.5);
}

TEST(FigureTest, TrapezoidClone) {
    geometry::Trapezoid t({0,0},{2,0},{3,2},{1,2});
    geometry::Figure* f = t.clone();
    geometry::Trapezoid* t_clone = dynamic_cast<geometry::Trapezoid*>(f);
    ASSERT_NE(t_clone, nullptr);
    EXPECT_NEAR(t_clone->Area(), 4.0, 1e-6);
    delete f;
}
