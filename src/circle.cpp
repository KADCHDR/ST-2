// Copyright 2022 UNN-CS
#include "../include/circle.h"
#include <cmath>
#include <stdexcept>

void Circle::updateFerence() { ference = 2 * PI * radius; }
void Circle::updateArea() { area = PI * radius * radius; }

void Circle::validateRadius(double r) {
  if (r < 0 || std::isnan(r) || std::isinf(r))
    throw std::invalid_argument("Invalid radius value");
}

Circle::Circle(double r) { setRadius(r); }

void Circle::setRadius(double r) {
  validateRadius(r);
  radius = r;
  updateFerence();
  updateArea();
}

void Circle::setFerence(double f) {
  if (f < 0 || std::isnan(f) || std::isinf(f))
    throw std::invalid_argument("Invalid ference value");
  radius = f / (2 * PI);
  validateRadius(radius);
  ference = f;
  updateArea();
}

void Circle::setArea(double a) {
  if (a < 0 || std::isnan(a) || std::isinf(a))
    throw std::invalid_argument("Invalid area value");
  radius = sqrt(a / PI);
  validateRadius(radius);
  area = a;
  updateFerence();
}

double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const { return area; }
