#include <math.h>
#include <cmath>
#include <iostream>

#include "lumiere.h"
#include "couleurRVB.hpp"
#include "objet3D.hpp"


RVB Lumiere_Ambiante::Illumination(const Rayon &, const Intersection3D & i, const Point3D &, Liste<Objet3D> &) const {
	RVB res;

	res = i.Objt()->Ambiante() * couleur;

	return res;
}


RVB Lumiere_Ponctuelle::Illumination(const Rayon & r, const Intersection3D & i, const Point3D & p, Liste<Objet3D> & lo) const {
    Vecteur3D vectIncident = this->Pos() - p;
    Vecteur3D vectIncidentNormalise = vectIncident;
    vectIncidentNormalise.Normaliser();

    Rayon rayon;
    rayon.Orig(p);
    rayon.Vect(vectIncidentNormalise);

    C_Liste_Intersection li;
    rayon.Intersections(li, lo);
    if(!li.Vide()){
        if(li.Premier()->Dist() < vectIncident.Longueur()){
            return RVB(0,0,0);
        }
    }

    float coef = vectIncidentNormalise * i.Norm();

    return  this->couleur * coef;
}

