#include <gtest/gtest.h>
#include "../include/FigureArray.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"
#include <cmath>

TEST(PentagonTest, AreaCalculation)
{

    std::pair<double, double> vertices[5] = {
        {1.0, 0.0},
        {0.309017, 0.9510565},
        {-0.809017, 0.5877852},
        {-0.809017, -0.5877852},
        {0.309017, -0.9510565}};
    Pentagon pentagon(vertices);

    double area = pentagon.Area();

    double expected_area = 2.37764;
    EXPECT_NEAR(area, expected_area, 0.0001);
}

TEST(PentagonTest, CenterCalculation)
{

    std::pair<double, double> vertices[5] = {
        {1.0, 0.0},
        {0.309017, 0.9510565},
        {-0.809017, 0.5877852},
        {-0.809017, -0.5877852},
        {0.309017, -0.9510565}};
    Pentagon pentagon(vertices);

    auto center = pentagon.Center();

    EXPECT_NEAR(center.first, 0.0, 0.0001);
    EXPECT_NEAR(center.second, 0.0, 0.0001);
}

TEST(PentagonTest, CopyConstructor)
{

    std::pair<double, double> vertices[5] = {
        {1.0, 0.0},
        {0.309017, 0.9510565},
        {-0.809017, 0.5877852},
        {-0.809017, -0.5877852},
        {0.309017, -0.9510565}};
    Pentagon pentagon1(vertices);

    Pentagon pentagon2(pentagon1);

    EXPECT_TRUE(pentagon1 == pentagon2);
}

TEST(PentagonTest, AssignmentOperator)
{

    std::pair<double, double> vertices1[5] = {
        {1.0, 0.0},
        {0.309017, 0.9510565},
        {-0.809017, 0.5877852},
        {-0.809017, -0.5877852},
        {0.309017, -0.9510565}};
    std::pair<double, double> vertices2[5] = {
        {0.309017, 0.9510565},
        {-0.809017, 0.5877852},
        {-0.809017, -0.5877852},
        {0.309017, -0.9510565},
        {1.0, 0.0}};
    Pentagon pentagon1(vertices1);
    Pentagon pentagon2(vertices2);

    pentagon2 = pentagon1;

    EXPECT_TRUE(pentagon1 == pentagon2);
}

TEST(HexagonTest, AreaCalculation)
{

    std::pair<double, double> vertices[6] = {
        {1.0, 0.0},
        {0.5, 0.8660254},
        {-0.5, 0.8660254},
        {-1.0, 0.0},
        {-0.5, -0.8660254},
        {0.5, -0.8660254}};
    Hexagon hexagon(vertices);

    double area = hexagon.Area();

    double expected_area = 2.59808;
    EXPECT_NEAR(area, expected_area, 0.0001);
}

TEST(HexagonTest, CenterCalculation)
{

    std::pair<double, double> vertices[6] = {
        {1.0, 0.0},
        {0.5, 0.8660254},
        {-0.5, 0.8660254},
        {-1.0, 0.0},
        {-0.5, -0.8660254},
        {0.5, -0.8660254}};
    Hexagon hexagon(vertices);

    auto center = hexagon.Center();

    EXPECT_NEAR(center.first, 0.0, 0.0001);
    EXPECT_NEAR(center.second, 0.0, 0.0001);
}

TEST(HexagonTest, CopyConstructor)
{

    std::pair<double, double> vertices[6] = {
        {1.0, 0.0},
        {0.5, 0.8660254},
        {-0.5, 0.8660254},
        {-1.0, 0.0},
        {-0.5, -0.8660254},
        {0.5, -0.8660254}};
    Hexagon hexagon1(vertices);

    Hexagon hexagon2(hexagon1);

    EXPECT_TRUE(hexagon1 == hexagon2);
}

TEST(HexagonTest, AssignmentOperator)
{

    std::pair<double, double> vertices1[6] = {
        {1.0, 0.0},
        {0.5, 0.8660254},
        {-0.5, 0.8660254},
        {-1.0, 0.0},
        {-0.5, -0.8660254},
        {0.5, -0.8660254}};
    std::pair<double, double> vertices2[6] = {
        {0.5, 0.8660254},
        {-0.5, 0.8660254},
        {-1.0, 0.0},
        {-0.5, -0.8660254},
        {0.5, -0.8660254},
        {1.0, 0.0}};
    Hexagon hexagon1(vertices1);
    Hexagon hexagon2(vertices2);

    hexagon2 = hexagon1;

    EXPECT_TRUE(hexagon1 == hexagon2);
}

TEST(OctagonTest, AreaCalculation)
{
    std::pair<double, double>
        vertices[8] = {
            {1.0, 0.0},
            {0.7071067811865476, 0.7071067811865475},
            {0.0, 1.0},
            {-0.7071067811865475, 0.7071067811865476},
            {-1.0, 0.0},
            {-0.7071067811865477, -0.7071067811865475},
            {0.0, -1.0},
            {0.7071067811865474, -0.7071067811865477}};
    Octagon octagon(vertices);

    double area = octagon.Area();
    double expected_area = 2.828427125;
    EXPECT_NEAR(area, expected_area, 1e-5);
}

TEST(OctagonTest, CenterCalculation)
{
    std::pair<double, double> vertices[8] = {
        {1.0, 0.0},
        {0.7071067811865476, 0.7071067811865475},
        {0.0, 1.0},
        {-0.7071067811865475, 0.7071067811865476},
        {-1.0, 0.0},
        {-0.7071067811865477, -0.7071067811865475},
        {0.0, -1.0},
        {0.7071067811865474, -0.7071067811865477}};
    Octagon octagon(vertices);

    auto center = octagon.Center();

    EXPECT_NEAR(center.first, 0.0, 1e-5);
    EXPECT_NEAR(center.second, 0.0, 1e-5);
}

TEST(OctagonTest, CopyConstructor)
{
    std::pair<double, double>
        vertices[8] = {
            {1.0, 0.0},
            {0.7071067811865476, 0.7071067811865475},
            {0.0, 1.0},
            {-0.7071067811865475, 0.7071067811865476},
            {-1.0, 0.0},
            {-0.7071067811865477, -0.7071067811865475},
            {0.0, -1.0},
            {0.7071067811865474, -0.7071067811865477}};
    Octagon octagon1(vertices);

    Octagon octagon2(octagon1);

    EXPECT_TRUE(octagon1 == octagon2);
}

TEST(OctagonTest, AssignmentOperator)
{
    std::pair<double, double>
        vertices1[8] = {
            {1.0, 0.0},
            {0.7071067811865476, 0.7071067811865475},
            {0.0, 1.0},
            {-0.7071067811865475, 0.7071067811865476},
            {-1.0, 0.0},
            {-0.7071067811865477, -0.7071067811865475},
            {0.0, -1.0},
            {0.7071067811865474, -0.7071067811865477}};
    std::pair<double, double> vertices2[8] = {
        {0.7071067811865476, 0.7071067811865475},
        {0.0, 1.0},
        {-0.7071067811865475, 0.7071067811865476},
        {-1.0, 0.0},
        {-0.7071067811865477, -0.7071067811865475},
        {0.0, -1.0},
        {0.7071067811865474, -0.7071067811865477},
        {1.0, 0.0}};
    Octagon octagon1(vertices1);
    Octagon octagon2(vertices2);

    octagon2 = octagon1;

    EXPECT_TRUE(octagon1 == octagon2);
}

TEST(FigureArrayTest, RemoveFigure)
{

    FigureArray figures;
    std::pair<double, double> vertices[5] = {
        {1.0, 0.0},
        {0.309017, 0.9510565},
        {-0.809017, 0.5877852},
        {-0.809017, -0.5877852},
        {0.309017, -0.9510565}};
    auto pentagon = new Pentagon(vertices);
    figures.push_back(pentagon);

    figures.removeAt(0);

    EXPECT_EQ(figures.getSize(), 0);
}

TEST(FigureArrayTest, TotalAreaCalculation)
{

    FigureArray figures;

    std::pair<double, double> pent_vertices[5] = {
        {1.0, 0.0},
        {0.309017, 0.9510565},
        {-0.809017, 0.5877852},
        {-0.809017, -0.5877852},
        {0.309017, -0.9510565}};
    auto pentagon = new Pentagon(pent_vertices);

    std::pair<double, double> hex_vertices[6] = {
        {1.0, 0.0},
        {0.5, 0.8660254},
        {-0.5, 0.8660254},
        {-1.0, 0.0},
        {-0.5, -0.8660254},
        {0.5, -0.8660254}};
    auto hexagon = new Hexagon(hex_vertices);

    std::pair<double, double> oct_vertices[8] = {
        {1.0, 0.0},
        {0.7071068, 0.7071068},
        {0.0, 1.0},
        {-0.7071068, 0.7071068},
        {-1.0, 0.0},
        {-0.7071068, -0.7071068},
        {0.0, -1.0},
        {0.7071068, -0.7071068}};
    auto octagon = new Octagon(oct_vertices);

    figures.push_back(pentagon);
    figures.push_back(hexagon);
    figures.push_back(octagon);

    double total_area = figures.totalArea();

    double expected_total_area = 2.37764 + 2.59808 + 2.82843;
    EXPECT_NEAR(total_area, expected_total_area, 0.001);
}

TEST(FigureArrayTest, CopyConstructor)
{

    FigureArray figures;
    std::pair<double, double> vertices[5] = {
        {1.0, 0.0},
        {0.309017, 0.9510565},
        {-0.809017, 0.5877852},
        {-0.809017, -0.5877852},
        {0.309017, -0.9510565}};
    auto pentagon = new Pentagon(vertices);
    figures.push_back(pentagon);

    FigureArray figures_copy(figures);

    EXPECT_EQ(figures_copy.getSize(), figures.getSize());
    EXPECT_TRUE(*figures_copy[0] == *figures[0]);
}

TEST(FigureArrayTest, AssignmentOperator)
{

    FigureArray figures1;
    std::pair<double, double> vertices[5] = {
        {1.0, 0.0},
        {0.309017, 0.9510565},
        {-0.809017, 0.5877852},
        {-0.809017, -0.5877852},
        {0.309017, -0.9510565}};
    auto pentagon = new Pentagon(vertices);
    figures1.push_back(pentagon);

    FigureArray figures2;

    figures2 = figures1;

    EXPECT_EQ(figures2.getSize(), figures1.getSize());
    EXPECT_TRUE(*figures2[0] == *figures1[0]);
}
