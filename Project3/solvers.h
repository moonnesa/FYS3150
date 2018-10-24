#ifndef SOLVERS_H
#define SOLVERS_H
#include "wanderer.h"
#include "vec3.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;

class solvers {
private:
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
  double pi = M_PI;

public:
  friend class wanderer;
  double radius;

  solvers();
  solvers(double r);
  void euler(wanderer &current, wanderer &other, int n, double h);
  void verlet(wanderer &current, wanderer &other, int n, double h);
};

#endif // SOLVERS_H
