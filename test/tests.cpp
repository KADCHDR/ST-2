// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include <limits>
#include "../include/tasks.h"
#include "../include/circle.h"

TEST(CircleTest, ConstructorValidRadius) {
  Circle c(5.0);
  ASSERT_NEAR(5.0, c.getRadius(), 1e-9);
}

TEST(CircleTest, ConstructorZeroRadius) {
  Circle c(0.0);
  ASSERT_NEAR(0.0, c.getRadius(), 1e-9);
}

TEST(CircleTest, ConstructorNegativeRadius) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(CircleTest, CanSetValidRadius) {
  Circle c(2.0);
  ASSERT_NO_THROW(c.setRadius(10.0));
}

TEST(CircleTest, SetValidRadius) {
  Circle c(2.0);
  c.setRadius(10.0);
  ASSERT_NEAR(10.0, c.getRadius(), 1e-9);
}

TEST(CircleTest, SetZeroRadius) {
  Circle c(5.0);
  c.setRadius(0.0);
  ASSERT_NEAR(0.0, c.getFerence(), 1e-9);
}

TEST(CircleTest, SetNegativeRadius) {
  Circle c(5.0);
  EXPECT_THROW(c.setRadius(-1.0), std::invalid_argument);
}

TEST(CircleTest, PrecisionFerenceCalculation) {
  Circle c(1.0);
  ASSERT_NEAR(2 * PI, c.getFerence(), 1e-9);
}

TEST(CircleTest, PrecisionAreaCalculation) {
  Circle c(2.0);
  ASSERT_NEAR(PI * 4.0, c.getArea(), 1e-9);
}

TEST(CircleTest, MaxDoubleRadius) {
  double max = std::numeric_limits<double>::max();
  Circle c(max);
  ASSERT_NEAR(max, c.getRadius(), 1e-9);
}

TEST(CircleTest, MinDoubleRadius) {
  double min = std::numeric_limits<double>::min();
  Circle c(min);
  ASSERT_NEAR(min, c.getRadius(), 1e-9);
}

TEST(TasksTest, EarthRopeGapCalculation) {
  double gap = calculateGap();
  ASSERT_NEAR(1 / (2 * PI), gap, 1e-9);
}

TEST(TasksTest, PoolCostCalculation) {
  double cost = calculatePoolCost();
  double expected = (PI * (4 * 4 - 3 * 3) * 1000) + (2 * PI * 4 * 2000);
  ASSERT_NEAR(expected, cost, 1e-9);
}

TEST(CircleTest, SetInvalidFerence) {
  Circle c(5.0);
  EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(CircleTest, SetNaNRadius) {
  Circle c(5.0);
  EXPECT_THROW(c.setRadius(NAN), std::invalid_argument);
}

TEST(CircleTest, SetInfArea) {
  Circle c(5.0);
  EXPECT_THROW(c.setArea(INFINITY), std::invalid_argument);
}

TEST(CircleTest, ChainSetters) {
  Circle c(3.0);
  c.setFerence(20.0);
  c.setArea(c.getArea() * 2);
  ASSERT_NEAR(63.66, c.getArea(), 0.01);
}

TEST(CircleTest, StateConsistency) {
  Circle c(5.0);
  double initialArea = c.getArea();
  c.setRadius(5.0);
  ASSERT_NEAR(initialArea, c.getArea(), 1e-9);
}

TEST(TasksTest, EarthRopeEdgeCase) {
  double earthRadius = 6378100;
  Circle earth(earthRadius);
  earth.setFerence(earth.getFerence() + 1);
  EXPECT_GT(earth.getRadius(), earthRadius);
}

TEST(TasksTest, PoolCostComponents) {
  double concrete = (PI * (4 * 4 - 3 * 3)) * 1000;
  double fence = (2 * PI * 4) * 2000;
  ASSERT_NEAR(concrete + fence, calculatePoolCost(), 1e-9);
}
