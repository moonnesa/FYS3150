#include "wanderer.h"


wanderer::wanderer(){
    x = 1.;
    y = 1.;
    z = 1.;
    vx = 1.;
    vy = 1.;
    vz = 1.;
    mass = 1.;
    name = "";
}

wanderer::wanderer(vec3 position, vec3 velocity, const double M, string N) {
    x = position[0];
    y = position[1];
    z = position[2];
    vx = velocity[0];
    vy = velocity[1];
    vz = velocity[2];
    mass = M;
    name = N;
}

string wanderer::getName(){
    return name;
}

double wanderer::distance(wanderer otherwanderer) {
    x = x - otherwanderer.x;
    y = y - otherwanderer.y;
    z = z - otherwanderer.z;
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

vec3 wanderer::GForce(wanderer otherwanderer) {
    double M1, M2, r;
    M1 = mass;
    M2 = otherwanderer.mass;
    r = distance(otherwanderer);
    Fg[0] = -G * (M2 * M1 / pow(r, 3)) * x;
    Fg[1] = -G * (M2 * M1 / pow(r, 3)) * y;
    Fg[2] = -G * (M2 * M1 / pow(r, 3)) * z;
    return Fg;
}

vec3 wanderer::acceleration(wanderer otherwanderer) {
    vec3 acceleration;
    double r = distance(otherwanderer);
    acceleration[0] = -G * x / pow(r, 3);
    acceleration[1] = -G * y / pow(r, 3);
    acceleration[2] = -G * z / pow(r, 3);
    return acceleration;
}
