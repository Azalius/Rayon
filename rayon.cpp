#include <limits>
#include <iostream>
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

	return !(li.Vide());
}

RVB Rayon::Lancer(Liste<Objet3D> & lo, Liste<Lumiere> & ll, int recur) const {
    RVB refr;
    RVB refl;

	C_Liste_Intersection lu;
	this->Intersections(lu, lo);

    if (lu.Vide() || recur == 0){
        return RVB(0, 0, 0);
    }
    Objet3D *colObj = lu.Premier()->Objt();

    //Appel recursif sur la premiére intersection

    Vecteur3D norm = lu.Premier()->Norm();
    norm.Normaliser();
    Vecteur3D vecReflechi = this->Vect().Reflechir(norm);
    vecReflechi.Normaliser();
    Rayon reflechi = Rayon(colObj->interPoint(*this), vecReflechi, this->Milieu());
    refl = reflechi.Lancer(lo, ll, recur - 1) * colObj->Kr();
    //std::cout<<"Rayon reflechi : "<<reflechi.Vect().X()<<" "<<reflechi.Vect().Y()<<" "<<reflechi.Vect().Z() <<std::endl;

    Vecteur3D vecRefracte = this->Vect().Refracter(norm, colObj->Milieu1(), colObj->Milieu2());
    vecRefracte.Normaliser();
    Rayon refracte = Rayon(colObj->interPoint(*this), vecRefracte, colObj->Milieu2());
    refr = refracte.Lancer(lo, ll, recur - 1) * colObj->Kt();
    //std::cout<<"Rayon refracte : "<<refracte.Vect().X()<<" "<<refracte.Vect().Y()<<" "<<refracte.Vect().Z() <<std::endl;

    //Verifie si eclairage d'une lumiére

    Lumiere *enCours = ll.Premier();
    RVB ilumDirect = RVB();
    for (int i = 0 ; i < ll.Nb_item() ; i++){
        ilumDirect += enCours->Illumination(*this, *lu.Premier(), colObj->interPoint(*this), lo);
        enCours = ll.Suivant();
    }
    //ilumDirect.Borner(0.0, 0.8);
	return ilumDirect*colObj->Couleur()+ refl + refr;
}

