// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#icnlude <cmath>
#include <cstdint>
#include "circle.h"

TEST(CircleTest, InitializationWithRadius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 10.0 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), 25.0 * M_PI);
}

TEST(CircleTest, SetRadiusUpdatesParameters) {
    Circle c(2.0);
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 6.0 * M_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), 9.0 * M_PI);
}

TEST(CircleTest, SetFerenceUpdatesRadiusAndArea) {
    Circle c(1.0);
    c.setFerence(4.0 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 4.0 * M_PI);
}

TEST(CircleTest, SetAreaUpdatesRadiusAndFerence) {
    Circle c(2.0);
    c.setArea(16.0 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 8.0 * M_PI);
}

TEST(CircleTest, NegativeRadiusSetsAbsoluteValue) {
    Circle c(-3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 6.0 * M_PI);
}

TEST(CircleTest, ZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, LargeRadiusPrecision) {
    Circle c(1e6);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e6, 1e-6);
    EXPECT_NEAR(c.getArea(), M_PI * 1e12, 1e-6);
}

TEST(CircleTest, SequentialUpdates) {
    Circle c(10.0);
    c.setFerence(20.0 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
    c.setArea(100.0 * M_PI);
    EXPECT_NEAR(c.getRadius(), 10.0, 1e-9);
}

TEST(RopeProblemTest, GapIs1Over2Pi) {
    double gap = solveRopeProblem();
    EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-6);
}

TEST(RopeProblemTest, GapIsRadiusIndependent) {
    Circle c(1000.0);
    double initialFerence = c.getFerence();
    c.setFerence(initialFerence + 1.0);
    double gap = c.getRadius() - 1000.0;
    EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-6);
}

TEST(PoolProblemTest, ConcreteCostCalculation) {
    PoolResult res = calculatePoolCost();
    double expectedArea = M_PI * (4.0*4.0 - 3.0*3.0);
    EXPECT_NEAR(res.concreteCost, expectedArea * 1000.0, 1e-6);
}

TEST(PoolProblemTest, FenceCostCalculation) {
    PoolResult res = calculatePoolCost();
    double expectedFerence = 2 * M_PI * 4.0;
    EXPECT_NEAR(res.fenceCost, expectedFerence * 2000.0, 1e-6);
}

TEST(PoolProblemTest, ZeroWidthPath) {
    auto calc = [](double width) {
        double poolRadius = 3.0;
        Circle outer(poolRadius + width);
        Circle pool(poolRadius);
        return (outer.getArea() - pool.getArea()) * 1000.0;
    };
    EXPECT_DOUBLE_EQ(calc(0.0), 0.0);
}

TEST(PoolProblemTest, NegativeWidthPath) {
    auto calc = [](double width) {
        double poolRadius = 3.0;
        double outerRadius = poolRadius + (width > 0 ? width : 0);
        Circle outer(outerRadius);
        Circle pool(poolRadius);
        return (outer.getArea() - pool.getArea()) * 1000.0;
    };
    EXPECT_DOUBLE_EQ(calc(-1.0), 0.0);
}

TEST(PoolProblemTest, DifferentPoolRadius) {
    auto calc = [](double poolRadius) {
        double width = 1.0;
        Circle outer(poolRadius + width);
        Circle pool(poolRadius);
        return (outer.getArea() - pool.getArea()) * 1000.0;
    };
    EXPECT_NEAR(calc(5.0), M_PI * (36.0 - 25.0) * 1000.0, 1e-6);
}

TEST(IntegrationTest, CircleFullCycle) {
    Circle c(2.0);
    c.setFerence(6.0 * M_PI);
    EXPECT_NEAR(c.getRadius(), 3.0, 1e-6);
    c.setArea(28.274333882308138);
    EXPECT_NEAR(c.getRadius(), 3.0, 1e-6);
}

TEST(IntegrationTest, TasksDependOnCircle) {
    double gap = solveRopeProblem();
    EXPECT_GT(gap, 0.15);
    EXPECT_LT(gap, 0.16);

    PoolResult res = calculatePoolCost();
    EXPECT_GT(res.concreteCost, 21990);
    EXPECT_LT(res.concreteCost, 21992);
}

TEST(CircleTest, TinyRadiusPrecision) {
    Circle c(1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e-9, 1e-20);
    EXPECT_NEAR(c.getArea(), M_PI * 1e-18, 1e-30);
}

TEST(CircleTest, NegativeFerenceHandling) {
    Circle c(1.0);
    c.setFerence(-10.0 * M_PI);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 25.0 * M_PI);
}

TEST(CircleTest, DoubleUpdateConsistency) {
    Circle c(2.0);
    c.setRadius(5.0);
    c.setFerence(20.0 * M_PI);
    c.setArea(100.0 * M_PI);
    EXPECT_NEAR(c.getRadius(), 10.0, 1e-6);
    EXPECT_NEAR(c.getFerence(), 20.0 * M_PI, 1e-6);
}
