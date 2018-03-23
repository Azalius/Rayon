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
    std::cout<<"..."<<std::endl;
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

RVB Lumiere_Smooth::Illumination(const Rayon &r, const Intersection3D &inte, const Point3D &p, Liste<Objet3D> &lo) const {

    float ecart = this->width/this->nbLums;
    Point3D corner = this->Pos() + Point3D(-1, -1, -1) * (this->width /2);
    RVB aRet = RVB(0, 0, 0);

    for (int i = 0; i < nbLums ; i++){
        for (int j = 0 ; j<nbLums ; j++){
            for (int k = 0 ; k<nbLums ; k++){
                Point3D src = corner + Point3D (1, 0, 0) * i + Point3D (0, 1, 0) * j + Point3D (0, 0, 1) * k;
                bool collide = false;

                Vecteur3D vectIncident = src - p;
                Vecteur3D vectIncidentNormalise = vectIncident;
                vectIncidentNormalise.Normaliser();

                Rayon rayon;
                rayon.Orig(p);
                rayon.Vect(vectIncidentNormalise);

                C_Liste_Intersection li;
                rayon.Intersections(li, lo);
                if(!li.Vide()){
                    if(li.Premier()->Dist() < vectIncident.Longueur()){
                        collide = true;
                    }
                }
                if (!collide){
                    float coef = vectIncidentNormalise * inte.Norm();
                    aRet += this->couleur * coef;
                }
            }
        }
    }
    return  aRet * (1.0 / (nbLums*nbLums*nbLums));


}