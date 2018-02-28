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
	RVB res;

	if (recur > MAX_RECUR || lo.Vide()){
		return RVB(0,0,0);
	}

	C_Liste_Intersection *lu = new C_Liste_Intersection;
	this->Intersections(*lu, lo);

	//TODO finir
	return res;
}

