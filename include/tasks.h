// Copyright 2022 UNN-CS
#pragma once

struct PoolResult {
    double concreteCost;
    double fenceCost;
};

double solveRopeProblem();
PoolResult calculatePoolCost();
