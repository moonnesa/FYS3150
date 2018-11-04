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
    p = position;
    v = velocity;
    x = p[0];
    y = p[1];
    z = p[2];
    vx = v[0];
    vy = v[1];
    vz = v[2];
    mass = M;
    name = N;
}

string wanderer::getName(){
    return name;
}

vec3 wanderer::getPosition(){
    return p;
}
vec3 wanderer::getVelocity(){
    return v;
}

double wanderer::distance(wanderer otherwanderer) {
    p[0] = p[0]-otherwanderer.p[0];;
    p[1] = p[1]-otherwanderer.p[1];;
    p[2] = p[2]-otherwanderer.p[2];;
    return sqrt(pow(p[0], 2) + pow(p[1], 2) + pow(p[2], 2));
}

vec3 wanderer::resetForces(){
    Fg = vec3(0,0,0);
    return Fg;

}

vec3 wanderer::computeGForce(wanderer otherwanderer) {
    double M1, M2, r;
    M1 = mass;
    M2 = otherwanderer.mass;
    r = distance(otherwanderer);
    Fg[0] = -G * (M2 * M1 / pow(r, 3)) * p[0]-otherwanderer.p[0];
    Fg[1] = -G * (M2 * M1 / pow(r, 3)) * p[1]-otherwanderer.p[1];
    Fg[2] = -G * (M2 * M1 / pow(r, 3)) * p[2]-otherwanderer.p[2];
    //cout << p[0] <<" "<<y<<" "<<z<< endl;
    return Fg;
}

vec3 wanderer::acceleration(wanderer otherwanderer) {
    vec3 acceleration;
    double M1 = mass;
    double M2 = otherwanderer.mass;
    acceleration[0] = this->computeGForce(otherwanderer)[0]/(M2*M1);
    acceleration[1] = this->computeGForce(otherwanderer)[1]/(M2*M1);
    acceleration[2] = this->computeGForce(otherwanderer)[2]/(M2*M1);
    //cout << acceleration << endl;
    return acceleration;
}
