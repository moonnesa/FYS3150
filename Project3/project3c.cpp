#include "iostream"
#include "solvers.h"

using namespace std;

int main(int argc, char *argv[]){

    double t = 100.0;
    int n = 10000;
    int N = n * int(t);
    double h = t / N;
    wanderer Earth(vec3(7.453686560033875E-01, 6.613720223585690E-01, -1.027876592750932E-04), vec3(-1.163250984946245E-02, 1.287870399958083E-02, -7.414303540778634E-07)*365, 0.0000003, "Earth");
    wanderer Jupiter(vec3(-2.523669115158531E+00, -4.728109414325424E+00, 7.606073663204352E-02), vec3(6.566708059406124E-03, -3.192862058609536E-03, -1.336200603474295E-04)*365, 0.0001, "Jupiter");
    wanderer Sun(vec3(0,0,0), vec3(0,0,0), 1, "Sun");
    // cout << planet1.distance(planet2) << endl;
    //vec3 Fg = Earth.GForce(Sun);
    solvers solver(Jupiter.distance(Sun));
    solvers solver_E(Earth.distance(Sun));
    solvers solver_EJ(Earth.distance(Jupiter));
    //double M = 2*pow(10,30);
    //cout << Earth.distance(Sun) << endl;
    //cout << Earth.GForce(Sun) << endl;
    //cout << sqrt(2*(4 * pow(M_PI, 2))*1) << endl;

    solver_EJ.verlet(Earth, Jupiter, N, h);
    solver_E.verlet(Earth, Sun, N, h);
    solver.verlet(Jupiter, Sun, N, h);
    return 0;

}
