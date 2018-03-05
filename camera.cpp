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

	for (int i  = 0 ; i < pm.Hauteur() ; i++){
		for (int j ; j < pm.Largeur() ; j++){
			Rayon r = Rayon(); //todo
			RVB coul = r.Lancer(lo, ll, 0);
		}
	}

}
