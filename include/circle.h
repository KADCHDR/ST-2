// Copyright 2022 UNN-CS

#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

const double PI = 3.1415926535;

class Circle {
 private:
  double radius;
  double ference;
  double area;

  void updateFerence();
  void updateArea();
  void validateRadius(double);

 public:
  explicit Circle(double radius);

  void setRadius(double radius);
  void setFerence(double ference);
  void setArea(double area);

  double getRadius() const;
  double getFerence() const;
  double getArea() const;
};

#endif // INCLUDE_CIRCLE_H_
