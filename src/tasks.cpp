// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

double solveRopeProblem() {
    const double earthRadius = 6378100.0;
    Circle earth(earthRadius);
    earth.setFerence(earth.getFerence() + 1.0);
    return earth.getRadius() - earthRadius;
}

PoolResult calculatePoolCost() {
    const double poolRadius = 3.0;
    const double width = 1.0;
    const double outerRadius = poolRadius + width;

    Circle pool(poolRadius);
    Circle outer(outerRadius);

    PoolResult result;
    result.concreteCost = (outer.getArea() - pool.getArea()) * 1000.0;
    result.fenceCost = outer.getFerence() * 2000.0;
    return result;
}
