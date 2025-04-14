// Copyright 2022 UNN-CS
#include "../include/tasks.h"
#include "../include/circle.h"

double calculateGap() {
  double earthRadius = 6378100;
  Circle earth(earthRadius);
  double ropeLength = earth.getFerence() + 1;
  earth.setFerence(ropeLength);
  return earth.getRadius() - earthRadius;
}

double calculatePoolCost() {
  double poolRadius = 3;
  double pathWidth = 1;
  double concreteCostPerSquareMeter = 1000;
  double fenceCostPerMeter = 2000;

  Circle pool(poolRadius);
  Circle poolWithPath(poolRadius + pathWidth);

  double pathArea = poolWithPath.getArea() - pool.getArea();
  double fenceLength = poolWithPath.getFerence();

  double totalConcreteCost = pathArea * concreteCostPerSquareMeter;
  double totalFenceCost = fenceLength * fenceCostPerMeter;

  return totalConcreteCost + totalFenceCost;
}
