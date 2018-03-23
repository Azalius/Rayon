//
// Created by Azalius on 23-Mar-18.
//

#include "Scenario.hpp"
#include "plan.hpp"
#include "sphere.hpp"


void ObjectScenario::toImage(char *path, bool outputText, int complexite) {

    if (outputText){
        std::cout<<"Debut de "<<path<<"..."<<std::endl;
    }
    Image bitmap;
    Pixelmap pm = Pixelmap(this->largeur, this->hauteur);
    cam.Calculer_image(pm, this->objs, this->lums, complexite, outputText);

    pm.Transferer(bitmap);
    bitmap.Enregistrer(path);
    if (outputText){
        std::cout<<path<<" enregistre."<<std::endl;
    }
}

    BaseScenario::BaseScenario(int largeur, int hauteur) {
        this->hauteur = hauteur;
        this->largeur =largeur;

        this->objs = Liste<Objet3D>();

        // Initialisation des lumieres
        Lumiere_Ambiante *ambiante = new Lumiere_Ambiante;
        ambiante->Couleur(RVB(0.1, 0.1, 0.1));
        this->lums.Ajouter(ambiante);

        Lumiere_Smooth *ponctuelle = new Lumiere_Smooth();
        ponctuelle->Couleur(RVB(0.9, 0.9, 0.9));
        ponctuelle->Pos(Point3D(-1, 40, 10));
        ponctuelle->NbLums(3);
        ponctuelle->Width(3);
        this->lums.Ajouter(ponctuelle);

        // Initialisation des objets==============================

        // Le plan vertical : le mur
        Plan *mur = new Plan();
        mur->depuisVetP(Vecteur3D(0.2, 0, 1), Point3D(0, 0, -10));
        mur->Couleur(RVB(0.95, 0.55, 0.25));
        mur->Ambiante(0.1);
        mur->Reflexion(0.0);
        this->objs.Ajouter(mur);

        // La grosse sphere
        Sphere *spher2 = new Sphere;
        spher2->Centre(Point3D(-3.5, 3, 0.5));
        spher2->SphereRayon(3);
        spher2->Couleur(RVB(1, 0.75, 0.75));
        spher2->Reflexion(0.75);
        this->objs.Ajouter(spher2);

        // Une sphere en verre
        Sphere *spher3 = new Sphere;
        spher3->Centre(Point3D(3.5, 4, 5));
        spher3->SphereRayon(1);
        spher3->Couleur(RVB(1, 1, 1));
        spher3->Transparence(0.85);
        spher3->Reflexion(0.15);
        spher3->Milieu_int(1.5);
        this->objs.Ajouter(spher3);

        // La moyenne sphere
        Sphere* spher1 = new Sphere();
        spher1->Centre(Point3D(2.5, 4, 0));
        spher1->SphereRayon(2);
        spher1->Couleur(RVB(0.75, 0.75, 1));
        spher1->Transparence(0);
        spher1->Milieu_int(1);
        spher1->Reflexion(0);
        spher1->Speculaire(RVB(1,0,1));
        spher1->Ks(0.6);
        spher1->Diffuse(RVB(1,0,1));
        spher1->Kd(0.8);
        spher1->Ka(0.3);
        this->objs.Ajouter(spher1);

        // Le plan horizontal : le sol
        Plan *sol = new Plan();
        sol->depuisVetP(Vecteur3D(0, 1, 0), Point3D(0, 0, 0));
        sol->Couleur(RVB(0.75, 1, 0.75));
        sol->Reflexion(0.6);
        this->objs.Ajouter(sol);

        // la Camera
        Camera *cam = new Camera();
        cam->Centre(Point3D(0, 5, 12));
        cam->Dir(Point3D(0, 1, 0));
        cam->Haut(Vecteur3D(0, 1, 0));
        cam->Largeur((5.6 * this->largeur) / this->hauteur);
        cam->Hauteur(5.6);
        this->cam = *cam;

    }
