#ifndef SPHERE_H
#define SPHERE_H

// raylib magic
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <string>
#include <map>

// === Planet Info Struct ===
struct PlanetInfo {
    std::string name;
    double mass_kg;
    double radius_km;
};

// === Sphere Class ===
class Sphere {
public:
    // Default constructor
    Sphere() {
        vec = { 0, 0, 0 };
        vel = { 0, 0, 0 };
        radius = 1;
        mass = 0;
    }

    // Constructor with position
    Sphere(float xCoords, float yCoords, float zCoords) {
        vec = Vector3{ xCoords, yCoords, zCoords };
        vel = { 0, 0, 0 };
        radius = 1;
        mass = 0;
    }

    // === Getters ===
    Vector3 getCoords() const { return vec; }
    Vector3 getVelocity() const { return vel; }
    float getRadius() const { return radius; }
    float getMass() const { return mass; }

    // === Setters ===
    void setCoords(float xCoords, float yCoords, float zCoords) {
        vec = Vector3{ xCoords, yCoords, zCoords };
    }

    void setVelocity(double xVel, double yVel, double zVel) {
        vel = Vector3{ static_cast<float>(xVel), static_cast<float>(yVel), static_cast<float>(zVel) };
    }

    void setRadius(float rad) { radius = rad; }
    void setMass(float m) { mass = m; }

private:
    float radius;
    float mass;
    Vector3 vec; // Position
    Vector3 vel; // Velocity
};

// === Planet Constants ===
static PlanetInfo sun     = { "Sun",     1.989e30,  695700.0 / 100};
static PlanetInfo mercury = { "Mercury", 3.301e23,  2439.7  / 10  };
static PlanetInfo venus   = { "Venus",   4.867e24,  6051.8  / 10 };
static PlanetInfo earth   = { "Earth",   5.972e24,  6371.0  / 10 };
static PlanetInfo mars    = { "Mars",    6.417e23,  3389.5  / 10 };

// === Lookup Map ===
static std::map<std::string, PlanetInfo> planetMap = {
    { "Sun", sun },
    { "Mercury", mercury },
    { "Venus", venus },
    { "Earth", earth },
    { "Mars", mars }
};

// === PlanetInfo → Sphere Conversion ===
inline Sphere PlanetToSphere(const PlanetInfo& planet, Vector3 position = { 0, 0, 0 }) {
    Sphere s(position.x, position.y, position.z);
    s.setRadius(static_cast<float>(planet.radius_km / 1000.0f)); // optional scale: km → units
    s.setMass(static_cast<float>(planet.mass_kg));
    return s;
}

#endif // SPHERE_H
