#pragma once

struct PoolResult {
    double concreteCost;
    double fenceCost;
};

double solveRopeProblem();
PoolResult calculatePoolCost();
