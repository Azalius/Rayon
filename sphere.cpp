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
    float C = (r.Orig()-this->Centre()) * (r.Orig()-this->Centre()) - this->rayon*this->rayon;

    float D = B*B-4*A*C;
    if (D < 0.0){
        return false;
    }
    D = sqrt(D);
    float T0 = (-B + D)/2*A;
    float T1 = (-B - D)/2*A;
	int aret = 0;

	if (T0 > 0){
		Intersection3D inter = Intersection3D(T0, this, this->milieu1);
		inter.Norm(this->Normale(r.Orig()+r.Vect()*T0));
		l.Ajouter(inter); // le bon milieu?
		aret = 1;
	}
		if (T1 > 0 && D != 0){
			Intersection3D inter = Intersection3D(T1, this, this->milieu1);
			inter.Norm(this->Normale(r.Orig()+r.Vect()*T1));
			l.Ajouter(inter); // le bon milieu?
			aret = 1;

	}

	return aret;
}

