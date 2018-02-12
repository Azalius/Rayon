// ce Fichier entier en TODO ?

#include <math.h>
#include "bases3d.hpp"

Point3D Point3D::operator +(const Vecteur3D & v) const {
	Point3D res;

// A FAIRE

	return res;
}

Point3D Point3D::operator -(const Vecteur3D & v) const {
	Point3D res;

	// A FAIRE

	return res;
}

Vecteur3D Point3D::operator -(const Point3D & p) const {
	Vecteur3D v(p, *this);

	return v;
}


// --------------------------------------------------------------------------

float Vecteur3D::Longueur() const {
	return sqrt((x * x) + (y * y) + (z * z));
}

void Vecteur3D::Normaliser() {
	// A FAIRE
}

Vecteur3D Vecteur3D::operator +(const Vecteur3D & v) const {
	Vecteur3D res;

	// A FAIRE

	return res;
}

Vecteur3D Vecteur3D::operator -(const Vecteur3D & v) const {
	Vecteur3D res;

	// A FAIRE

	return res;
}

Vecteur3D Vecteur3D::operator -() const {
	Vecteur3D res;

	// A FAIRE

	return res;
}

Vecteur3D Vecteur3D::operator *(float m) const {
	Vecteur3D res;

	// A FAIRE

	return res;
}

float Vecteur3D::operator *(const Vecteur3D & v) const {
	return ((x * v.x) + (y * v.y) + (z * v.z));
}

Vecteur3D Vecteur3D::Cross(const Vecteur3D & v) const {
	Vecteur3D res;

	// A FAIRE

	return res;
}

Vecteur3D Vecteur3D::Reflechir(const Vecteur3D & n) const { //TODO
	Vecteur3D res = (*this) - (n * (2 * (n * (*this))));

	return res;
}

Vecteur3D Vecteur3D::Refracter(const Vecteur3D & norm, float m1, float m2) const { // TODO
	Vecteur3D res;

	// A FAIRE

	return res;
}

