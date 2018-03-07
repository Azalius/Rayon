#include <math.h>
#include "sphere.hpp"


Vecteur3D Sphere::Normale(const Point3D & t) const {
	Vecteur3D res(centre, t);
	res.Normaliser();
	return res;
}


int Sphere::Intersection(const Rayon & r, C_Liste_Intersection & l) {

    float B = (r.Orig()-this->Centre()) * 2.0 * r.Vect();
    float A = 1;
    float C = (r.Orig()-this->Centre()) * (r.Orig()-this->Centre()) - this->rayon;

    float D = B*B-4*A*C;
    if (D < 0.0){
        return false;
    }
    D = sqrt(D);
    float T0 = 0,5*(-B - D);
    float T1 = 0,5*(-B + D);

    l.Ajouter(Intersection3D(T0, this, this->milieu1)); // le bon milieu?
    if (D != 0){
        l.Ajouter(Intersection3D(T1, this, this->milieu1));
    }
	return 1;
}
Point3D	Sphere::interPoint(Rayon r) {
	C_Liste_Intersection liste;
	Point3D res = Point3D();


	if (this->Intersection(r, liste)) {
		float dist = INFINITY;
		for (liste.Premier(); liste.Courant() != 0; liste.Suivant()) {
			if (liste.Courant()->Dist < dist) {
				dist = liste.Courant->Dist;
			}
		}
		res = r.Orig+(r.Vect()*dist);
	}
	return res;
}
