#include "solvers.h"

int main(int argc, char *argv[]){

    double t = 10.0;
    int n = 1000;
    int N = n * t;
    double h = t / N;
    wanderer Earth(vec3(1, 0, 0), vec3(0, 2*M_PI, 0), 0.0000003, "Earth");
    wanderer Sun(vec3(0, 0, 0), vec3(0, 0, 0), 1, "Sun");
    // cout << planet1.distance(planet2) << endl;
    vec3 Fg = Earth.GForce(Sun);
    solvers solver(Earth.distance(Sun));
    solver.verlet(Earth, Sun, N, h);
    solver.euler(Earth, Sun, N, h);
    return 0;

}
