// // tests.cpp
// #include <gtest/gtest.h>
// #include "Array.hpp"
// #include "Pentagon.hpp"
// #include "Hexagon.hpp"
// #include "Octagon.hpp"
// #include <cmath>
// #include <memory>

// TEST(PentagonTest, AreaCalculation) {
//     std::array<Point<double>, 5> vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.309017, 0.9510565),
//         Point<double>(-0.809017, 0.5877852),
//         Point<double>(-0.809017, -0.5877852),
//         Point<double>(0.309017, -0.9510565)
//     };
//     Pentagon<double> pentagon(vertices);

//     double area = pentagon.Area();
//     double expected_area = 2.37764;

//     EXPECT_NEAR(area, expected_area, 0.0001);
// }

// TEST(PentagonTest, CenterCalculation) {
//     std::array<Point<double>, 5> vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.309017, 0.9510565),
//         Point<double>(-0.809017, 0.5877852),
//         Point<double>(-0.809017, -0.5877852),
//         Point<double>(0.309017, -0.9510565)
//     };
//     Pentagon<double> pentagon(vertices);

//     auto center = pentagon.Center();

//     EXPECT_NEAR(center.x, 0.0, 0.0001);
//     EXPECT_NEAR(center.y, 0.0, 0.0001);
// }

// TEST(PentagonTest, CopyConstructor) {
//     std::array<Point<double>, 5> vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.309017, 0.9510565),
//         Point<double>(-0.809017, 0.5877852),
//         Point<double>(-0.809017, -0.5877852),
//         Point<double>(0.309017, -0.9510565)
//     };
//     Pentagon<double> pentagon1(vertices);
//     Pentagon<double> pentagon2(pentagon1);

//     EXPECT_TRUE(pentagon1 == pentagon2);
// }

// TEST(PentagonTest, AssignmentOperator) {
//     std::array<Point<double>, 5> vertices1 = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.309017, 0.9510565),
//         Point<double>(-0.809017, 0.5877852),
//         Point<double>(-0.809017, -0.5877852),
//         Point<double>(0.309017, -0.9510565)
//     };
//     std::array<Point<double>, 5> vertices2 = {
//         Point<double>(0.309017, 0.9510565),
//         Point<double>(-0.809017, 0.5877852),
//         Point<double>(-0.809017, -0.5877852),
//         Point<double>(0.309017, -0.9510565),
//         Point<double>(1.0, 0.0)
//     };
//     Pentagon<double> pentagon1(vertices1);
//     Pentagon<double> pentagon2(vertices2);

//     pentagon2 = pentagon1;

//     EXPECT_TRUE(pentagon1 == pentagon2);
// }

// TEST(HexagonTest, AreaCalculation) {
//     std::array<Point<double>, 6> vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.5, 0.8660254),
//         Point<double>(-0.5, 0.8660254),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.5, -0.8660254),
//         Point<double>(0.5, -0.8660254)
//     };
//     Hexagon<double> hexagon(vertices);

//     double area = hexagon.Area();
//     double expected_area = 2.59808;

//     EXPECT_NEAR(area, expected_area, 0.0001);
// }

// TEST(HexagonTest, CenterCalculation) {
//     std::array<Point<double>, 6> vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.5, 0.8660254),
//         Point<double>(-0.5, 0.8660254),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.5, -0.8660254),
//         Point<double>(0.5, -0.8660254)
//     };
//     Hexagon<double> hexagon(vertices);

//     auto center = hexagon.Center();

//     EXPECT_NEAR(center.x, 0.0, 0.0001);
//     EXPECT_NEAR(center.y, 0.0, 0.0001);
// }

// TEST(HexagonTest, CopyConstructor) {
//     std::array<Point<double>, 6> vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.5, 0.8660254),
//         Point<double>(-0.5, 0.8660254),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.5, -0.8660254),
//         Point<double>(0.5, -0.8660254)
//     };
//     Hexagon<double> hexagon1(vertices);
//     Hexagon<double> hexagon2(hexagon1);

//     EXPECT_TRUE(hexagon1 == hexagon2);
// }

// TEST(HexagonTest, AssignmentOperator) {
//     std::array<Point<double>, 6> vertices1 = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.5, 0.8660254),
//         Point<double>(-0.5, 0.8660254),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.5, -0.8660254),
//         Point<double>(0.5, -0.8660254)
//     };
//     std::array<Point<double>, 6> vertices2 = {
//         Point<double>(0.5, 0.8660254),
//         Point<double>(-0.5, 0.8660254),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.5, -0.8660254),
//         Point<double>(0.5, -0.8660254),
//         Point<double>(1.0, 0.0)
//     };
//     Hexagon<double> hexagon1(vertices1);
//     Hexagon<double> hexagon2(vertices2);

//     hexagon2 = hexagon1;

//     EXPECT_TRUE(hexagon1 == hexagon2);
// }

// TEST(OctagonTest, AreaCalculation) {
//     std::array<Point<double>, 8> vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.70710678118, 0.70710678118),
//         Point<double>(0.0, 1.0),
//         Point<double>(-0.70710678118, 0.70710678118),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.70710678118, -0.70710678118),
//         Point<double>(0.0, -1.0),
//         Point<double>(0.70710678118, -0.70710678118)
//     };
//     Octagon<double> octagon(vertices);

//     double area = octagon.Area();
//     double expected_area = 2.82843;

//     EXPECT_NEAR(area, expected_area, 0.0001);
// }

// TEST(OctagonTest, CenterCalculation) {
//     std::array<Point<double>, 8> vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.70710678118, 0.70710678118),
//         Point<double>(0.0, 1.0),
//         Point<double>(-0.70710678118, 0.70710678118),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.70710678118, -0.70710678118),
//         Point<double>(0.0, -1.0),
//         Point<double>(0.70710678118, -0.70710678118)
//     };
//     Octagon<double> octagon(vertices);

//     auto center = octagon.Center();

//     EXPECT_NEAR(center.x, 0.0, 0.0001);
//     EXPECT_NEAR(center.y, 0.0, 0.0001);
// }

// TEST(OctagonTest, CopyConstructor) {
//     std::array<Point<double>, 8> vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.70710678118, 0.70710678118),
//         Point<double>(0.0, 1.0),
//         Point<double>(-0.70710678118, 0.70710678118),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.70710678118, -0.70710678118),
//         Point<double>(0.0, -1.0),
//         Point<double>(0.70710678118, -0.70710678118)
//     };
//     Octagon<double> octagon1(vertices);
//     Octagon<double> octagon2(octagon1);

//     EXPECT_TRUE(octagon1 == octagon2);
// }

// TEST(OctagonTest, AssignmentOperator) {
//     std::array<Point<double>, 8> vertices1 = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.70710678118, 0.70710678118),
//         Point<double>(0.0, 1.0),
//         Point<double>(-0.70710678118, 0.70710678118),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.70710678118, -0.70710678118),
//         Point<double>(0.0, -1.0),
//         Point<double>(0.70710678118, -0.70710678118)
//     };
//     std::array<Point<double>, 8> vertices2 = {
//         Point<double>(0.70710678118, 0.70710678118),
//         Point<double>(0.0, 1.0),
//         Point<double>(-0.70710678118, 0.70710678118),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.70710678118, -0.70710678118),
//         Point<double>(0.0, -1.0),
//         Point<double>(0.70710678118, -0.70710678118),
//         Point<double>(1.0, 0.0)
//     };
//     Octagon<double> octagon1(vertices1);
//     Octagon<double> octagon2(vertices2);

//     octagon2 = octagon1;

//     EXPECT_TRUE(octagon1 == octagon2);
// }

// TEST(ArrayTest, RemoveFigure) {
//     Array<std::shared_ptr<Figure<double>>> figures;

//     std::array<Point<double>, 5> pent_vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.309017, 0.9510565),
//         Point<double>(-0.809017, 0.5877852),
//         Point<double>(-0.809017, -0.5877852),
//         Point<double>(0.309017, -0.9510565)
//     };
//     auto pentagon = std::make_shared<Pentagon<double>>(pent_vertices);
//     figures.push_back(pentagon);

//     figures.removeAt(0);

//     EXPECT_EQ(figures.getSize(), 0);
// }

// TEST(ArrayTest, TotalAreaCalculation) {
//     Array<std::shared_ptr<Figure<double>>> figures;

//     std::array<Point<double>, 5> pent_vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.309017, 0.9510565),
//         Point<double>(-0.809017, 0.5877852),
//         Point<double>(-0.809017, -0.5877852),
//         Point<double>(0.309017, -0.9510565)
//     };
//     auto pentagon = std::make_shared<Pentagon<double>>(pent_vertices);

//     std::array<Point<double>, 6> hex_vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.5, 0.8660254),
//         Point<double>(-0.5, 0.8660254),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.5, -0.8660254),
//         Point<double>(0.5, -0.8660254)
//     };
//     auto hexagon = std::make_shared<Hexagon<double>>(hex_vertices);

//     std::array<Point<double>, 8> oct_vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.7071068, 0.7071068),
//         Point<double>(0.0, 1.0),
//         Point<double>(-0.7071068, 0.7071068),
//         Point<double>(-1.0, 0.0),
//         Point<double>(-0.7071068, -0.7071068),
//         Point<double>(0.0, -1.0),
//         Point<double>(0.7071068, -0.7071068)
//     };
//     auto octagon = std::make_shared<Octagon<double>>(oct_vertices);

//     figures.push_back(pentagon);
//     figures.push_back(hexagon);
//     figures.push_back(octagon);

//     double total_area = 0.0;
//     for (const auto& fig : figures) {
//         total_area += static_cast<double>(*fig);
//     }

//     double expected_total_area = 2.37764 + 2.59808 + 2.82843;
//     EXPECT_NEAR(total_area, expected_total_area, 0.001);
// }

// TEST(ArrayTest, CopyConstructor) {
//     Array<std::shared_ptr<Figure<double>>> figures;

//     std::array<Point<double>, 5> pent_vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.309017, 0.9510565),
//         Point<double>(-0.809017, 0.5877852),
//         Point<double>(-0.809017, -0.5877852),
//         Point<double>(0.309017, -0.9510565)
//     };
//     auto pentagon = std::make_shared<Pentagon<double>>(pent_vertices);
//     figures.push_back(pentagon);

//     Array<std::shared_ptr<Figure<double>>> figures_copy(figures);

//     EXPECT_EQ(figures_copy.getSize(), figures.getSize());
//     EXPECT_TRUE(*figures_copy[0] == *figures[0]);
// }

// TEST(ArrayTest, AssignmentOperator) {
//     Array<std::shared_ptr<Figure<double>>> figures1;

//     std::array<Point<double>, 5> pent_vertices = {
//         Point<double>(1.0, 0.0),
//         Point<double>(0.309017, 0.9510565),
//         Point<double>(-0.809017, 0.5877852),
//         Point<double>(-0.809017, -0.5877852),
//         Point<double>(0.309017, -0.9510565)
//     };
//     auto pentagon = std::make_shared<Pentagon<double>>(pent_vertices);
//     figures1.push_back(pentagon);

//     Array<std::shared_ptr<Figure<double>>> figures2;

//     figures2 = figures1;

//     EXPECT_EQ(figures2.getSize(), figures1.getSize());
//     EXPECT_TRUE(*figures2[0] == *figures1[0]);
// }
