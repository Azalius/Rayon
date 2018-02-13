// ce Fichier entier en TODO ?

#include <math.h>
#include "bases3d.hpp"

Point3D Point3D::operator +(const Vecteur3D & v) const {
	Point3D res;

	res.X(x + v.X());
	res.Y(y + v.Y());
	res.Z(z + v.Z());

	return res;
}

Point3D Point3D::operator -(const Vecteur3D & v) const {
	Point3D res;

	res.X(x - v.X());
	res.Y(y - v.Y());
	res.Z(z - v.Z());

	return res;
}

Vecteur3D Point3D::operator -(const Point3D & p) const {
	Vecteur3D v(p, *this);

	return v;
}

bool Point3D::operator ==(const Point3D &b) const {
	if (x == b.X() && y == b.Y() && z == b.Z()) return true;
	return false;
}


// --------------------------------------------------------------------------

float Vecteur3D::Longueur() const {
	return sqrt((x * x) + (y * y) + (z * z));
}

void Vecteur3D::Normaliser() {
    float longeur = Longueur(); // Eviter de le recalculer
    X(x/Longueur());
    Y(x/Longueur());
    Z(z/Longueur());
}

bool Vecteur3D::operator ==(const Vecteur3D &b) const {
	if (x == b.X() && y == b.Y() && z == b.Z()) return true;
	return false;
}

Vecteur3D Vecteur3D::operator +(const Vecteur3D & v) const {
	Vecteur3D res;

	res.X(x + v.X());
	res.Y(y + v.Y());
	res.Z(z + v.Z());

	return res;
}

Vecteur3D Vecteur3D::operator -(const Vecteur3D & v) const {
	Vecteur3D res;

	res.X(x - v.X());
	res.Y(y - v.Y());
	res.Z(z - v.Z());

	return res;
}

Vecteur3D Vecteur3D::operator -() const {
	Vecteur3D res;

	res.X(-x);
	res.Y(-y);
	res.Z(-z);

	return res;
}

Vecteur3D Vecteur3D::operator *(float m) const {
	Vecteur3D res;

	res.X(x*m);
	res.Y(y*m);
	res.Z(z*m);

	return res;
}

float Vecteur3D::operator *(const Vecteur3D & v) const {
	return ((x * v.x) + (y * v.y) + (z * v.z));
}

Vecteur3D Vecteur3D::Cross(const Vecteur3D & v) const {
	Vecteur3D res;

	res.X(y*v.Z()-z*v.Y());
    res.Y(z*v.X()-x*v.Z());
    res.Z(x*v.Y()-y*v.Y());

	return res;
}

Vecteur3D Vecteur3D::Reflechir(const Vecteur3D & n) const { //TODO
	Vecteur3D res = (*this) - (n * (2 * (n * (*this))));

	return res;
}

Vecteur3D Vecteur3D::Refracter(const Vecteur3D & norm, float m1, float m2) const { // TODO
	Vecteur3D res;
	float coef = m1/m2;
    float oldAngle = acos(((*this)*norm)/(Longueur()*norm.Longueur())); // signe?
    if (sin(oldAngle) > 1/coef){ // refraction totale, mb?
        return Vecteur3D(0,0,0);
    }
    float newAngle = asin(sin(oldAngle) / coef);

    res = sin(newAngle) * norm;
	return res;
}

