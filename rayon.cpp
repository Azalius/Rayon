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

	return !(lo.Vide());
}

RVB Rayon::Lancer(Liste<Objet3D> & lo, Liste<Lumiere> & ll, int recur) const {
    RVB refr;
    RVB refl;

    if (lo.Vide()){
        std::cout<<"no objects"<<std::endl;
    }
    if (ll.Vide()){
        std::cout<<"no lights"<<std::endl;
    }

	if (recur > 4 || lo.Vide() || ll.Vide()){
		return RVB(0,0.5,0.5);
	}
    std::cout<<"ima try"<<std::endl;

	C_Liste_Intersection *lu = new C_Liste_Intersection;
	this->Intersections(*lu, lo);

    if (lu->Vide()){
        //std::cout<<"No collide"<<std::endl;
        return RVB(0.5, 0, 0);
    }
    else{
        //std::cout<<"Collide"<<std::endl;
    }
    Objet3D *colObj = lu->Premier()->Objt();

    //Appel recursif sur la premiére intersection
    Rayon reflechi = Rayon(colObj->interPoint(*this), lu->Premier()->Norm().Reflechir(this->Vect()), colObj->Milieu1());
    refl = reflechi.Lancer(lo, ll, recur + 1) * colObj->Kr();
    //std::cout<<"Rayon reflechi : "<<reflechi.Vect().X()<<" "<<reflechi.Vect().Y()<<" "<<reflechi.Vect().Z() <<std::endl;
    Rayon refracte = Rayon(colObj->interPoint(*this), lu->Premier()->Norm().Refracter(this->Vect(), colObj->Milieu1(), colObj->Milieu2()), colObj->Milieu2());
    refr = refracte.Lancer(lo, ll, recur + 1) * colObj->Kt();
    //std::cout<<"Rayon refracte : "<<refracte.Vect().X()<<" "<<refracte.Vect().Y()<<" "<<refracte.Vect().Z() <<std::endl;

    //Verifie si eclairage d'une lumiére
    Lumiere *enCours = ll.Premier();
    RVB ilumDirect = RVB();
    for (int i = 0 ; i < ll.Nb_item() ; i++){
        ilumDirect += enCours->Illumination(*this, *lu->Premier(), colObj->interPoint(*this), lo);
        enCours = ll.Suivant();
    }

    if (recur == 0){
        return refr + refl + ilumDirect + colObj->Ambiante();
    }
    if (refl.B()+refl.R()+refl.V() != 0){
        //std::cout<<"Im trying"<<std::endl;
    }
	return refr + refl + ilumDirect;
}

