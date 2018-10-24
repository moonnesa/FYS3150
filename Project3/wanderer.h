#ifndef WANDERER_H
#define WANDERER_H

#include "vec3.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class wanderer
{
private:
  double G = 4 * pow(M_PI, 2);

public:
  double mass;
  vec3 position;
  vec3 velocity;
  double x, y, z;
  double vx, vy, vz;
  double ax, ay, az;
  string name;
  vec3 Fg;
  double pi = M_PI;

  wanderer();
  wanderer(vec3 position, vec3 velocity, const double M, string w_name);
  string getName();
  double distance(wanderer otherwanderer);
  vec3 GForce(wanderer otherwanderer);
  vec3 accel(wanderer otherwanderer);
  // double kinetic();
  // double potential(planet otherplanet);
};

#endif // WANDERER_H
