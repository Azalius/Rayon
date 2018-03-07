#include "camera.hpp"
#include "bases3d.hpp"
#include "pixelmap.hpp"
#include "rayon.hpp"
#include <stdio.h>

void Camera::Haut(const Vecteur3D & h) {

	haut = h - (dir * (dir * h));
	if (!haut.Nul())
		haut.Normaliser();
}

void Camera::Calculer_image(Pixelmap & pm, Liste<Objet3D> & lo, Liste<Lumiere> & ll, int complexite) const {
    //TODO gerer la comlexite
    Point3D centreEcran = this->Centre()+this->Dir()*dist;
    Vecteur3D axeY = Vecteur3D(0, 1, 0); // TODO si la camera n'est pas perp
    Vecteur3D axeZ = Vecteur3D(1, 0, 0); // ou cas general etc

    axeY.Normaliser(); // correspond à la hauteur
    axeZ.Normaliser(); // correspond a la largeur
	for (int i  = 0 ; i < pm.Hauteur() ; i++){
		for (int j = 0; j < pm.Largeur() ; j++){
            Vecteur3D dire = Vecteur3D();
            dire = this->dir;
            dire = dire + axeY * (i - pm.Hauteur()/2);
            dire = dire + axeZ * (j - pm.Largeur()/2);
			Rayon r = Rayon(this->Centre(), dir, 1);
			RVB coul = r.Lancer(lo, ll, 0);
            pm.Map(i, j, coul);
		}
	}

}
