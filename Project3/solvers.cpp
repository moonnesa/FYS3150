#include "solvers.h"

solvers::solvers() { radius = 1.0; }

solvers::solvers(double r) { radius = r; }

void solvers::euler(wanderer &current, wanderer &other, int n, double h) {
  x = current.x;
  y = current.y;
  z = current.z;
  vx = current.vx;
  vy = current.vy;
  vz = current.vz;
  ofstream ofile;


  ofile.open("Euler_array.txt");
  for (int i = 0; i < n; i++) {
    double r = current.distance(other);
    vx += -h * (4 * pow(M_PI, 2) / pow(r, 3)) * x;
    vy += -h * (4 * pow(M_PI, 2) / pow(r, 3)) * y;
    vz += -h * (4 * pow(M_PI, 2) / pow(r, 3)) * z;
    x += h * vx;
    y += h * vy;
    z += h * vz;

   ofile << x << " " << y << endl;

  }
  ofile.close();
  return;
}

void solvers::verlet(wanderer &current, wanderer &other, int n, double h) {
  x = current.x;
  y = current.y;
  z = current.z;
  vx = current.vx;
  vy = current.vy;
  vz = current.vz;
  double tmp_ax, tmp_ay, tmp_az;
  double hh = h * h;
  ofstream ofile;
  double ax, ay, az;

  ofile.open("Verlet_array.txt");
  for (int i = 0; i < n; i++) {
    double r = current.distance(other);
    // vec3 a = current.accel(other);
    tmp_ax = -4 * (pi * pi * x) / pow(r, 3);
    tmp_ay = -4 * (pi * pi * y) / pow(r, 3);
    tmp_az = -4 * (pi * pi * z) / pow(r, 3);
    x = x + h * vx + (hh / 2) * tmp_ax;
    y = y + h * vy + (hh / 2) * tmp_ay;
    z = z + h * vz + (hh / 2) * tmp_az;
    // cout << tmpax << endl;
    // a = current.accel(other);
    ax = -4 * (pi * pi * x) / pow(r, 3);
    ay = -4 * (pi * pi * y) / pow(r, 3);
    az = -4 * (pi * pi * z) / pow(r, 3);
    // cout << ax << ay << endl;
    vx = vx + (h / 2) * (ax + tmp_ax);
    vy = vy + (h / 2) * (ay + tmp_ay);
    vz = vz + (h / 2) * (az + tmp_az);
    ofile << x << " " << y << endl;
  }

  ofile.close();
  return;
}
