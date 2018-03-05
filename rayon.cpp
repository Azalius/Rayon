#include <limits>
#include "rayon.hpp"
#include "objet3D.hpp"
#include "lumiere.h"
#include "const.hpp"


int Rayon::Intersections(C_Liste_Intersection & li, Liste<Objet3D> & lo) const {
	// Il n'y a pas d'intersection au depart
	li.Vider();

	// Pour chaque objet 3D
	for (lo.Premier(); lo.Courant() != 0; lo.Suivant())
		lo.Courant()->Intersection(*this, li);

	return !(lo.Vide());
}

RVB Rayon::Lancer(Liste<Objet3D> & lo, Liste<Lumiere> & ll, int recur) const {
    RVB refr;
    RVB refl;

	if (recur > MAX_RECUR || lo.Vide() || ll.Vide()){
		return RVB(0,0,0);
	}

	C_Liste_Intersection *lu = new C_Liste_Intersection;
	this->Intersections(*lu, lo);
    Objet3D colObj = *lu->Premier()->Objt();

    Rayon reflechi = Rayon(, lu->Premier()->Norm().Reflechir(this->Vect()), colObj.Milieu1());
    refl = reflechi.Lancer(lo, ll, recur + 1) * colObj.Kr();
    Rayon refracte = Rayon(, lu->Premier()->Norm().Refracter(this->Vect(), colObj.Milieu1(), colObj.Milieu2()), colObj.Milieu2());
    refr = refracte.Lancer(lo, ll, recur + 1) * colObj.Kt();

    //ToFinir



    if (recur == 0){
        return refr + refl + colObj.Ambiante();
    }
	return refr + refl;
}

