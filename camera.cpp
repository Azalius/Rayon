#include "camera.hpp"
#include "bases3d.hpp"
#include "pixelmap.hpp"
#include "rayon.hpp"
#include <stdio.h>
#include <iostream>

void Camera::Haut(const Vecteur3D & h) {

	haut = h - (dir * (dir * h));
	if (!haut.Nul())
		haut.Normaliser();
}

void Camera::Calculer_image(Pixelmap & pm, Liste<Objet3D> & lo, Liste<Lumiere> & ll, int complexite) const {
    Point3D foyer; // Foyer optique de la camera
    Vecteur3D droite; // Vecteur partant sur la droite dans le plan de l'ecran
    float dx, dy; // dimension des macro-pixels
    int x, y; // Position dans l'image du pixel en cours de calcul
    Point3D hg; // Position du pixel au centre du premier macro-pixel de l'ecran (en haut a gauche)
    Point3D pt; // Position de l'intersection entre le rayon a lancer et l'ecran
    Rayon ray; // Rayon a lancer
    Vecteur3D vect; // Vecteur directeur du rayon a lancer
    int index; // Indice du pixel traite

    // On calcule la position du foyer de la camera
    foyer = centre - (dir * dist);

    // On calcule le vecteur unitaire "droite" du plan
    droite = dir.Cross(haut);

    // On calcule le deltaX et le deltaY
    dx = largeur / pm.Largeur();
    dy = hauteur / pm.Hauteur();

    // On calcule la position du premier point de l'ecran que l'on calculera
    hg = centre + (droite * ((dx / 2) - (largeur / 2))) + (haut * ((hauteur / 2) - (dy / 2)));

    // Pour chaque pixel de l'image a calculer
    index = 0;
    for (y = 0; y < pm.Hauteur(); y++) {
        for (x = 0; x < pm.Largeur(); x++) {
            // On calcule la position dans l'espace de ce point
            pt = hg + (droite * (dx * x)) - (haut * (dy * y));

            // On prepare le rayon qui part du foyer et qui passe par ce point
            ray.Orig(pt);
            vect = pt - foyer;
            vect.Normaliser();
            ray.Vect(vect);
            ray.Milieu(1); /* Cette supposition n'est pas toujours vraie */

            // Et on enregistre la couleur du rayon dans l'image
            pm.Map(index++, ray.Lancer(lo, ll, complexite));
        }
        printf("Ligne %d traitee\n", y);
    }
}

