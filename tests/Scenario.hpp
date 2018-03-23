//
// Created by Azalius on 23-Mar-18.
//

#ifndef IMAGE_SCENARIO_HPP
#define IMAGE_SCENARIO_HPP

#include <iostream>
#include <string>
#include "../lumiere.h"
#include "../camera.hpp"

class ObjectScenario {
protected:
    Liste<Lumiere> lums;
    Liste<Objet3D> objs;
    int hauteur;
    int largeur;
    Camera cam;

public:

    ObjectScenario() {

    }
    const Liste<Lumiere> getLums() const {
        return lums;
    }

    void setLums(const Liste<Lumiere> &lums) {
        this->lums = lums;
    }

    void setObjs(const Liste<Objet3D> &objs) {
        this->objs = objs;
    }

    void setHauteur(int hauteur) {
        this->hauteur = hauteur;
    }

    void setLargeur(int largeur) {
        this->largeur = largeur;
    }

    void setCam(const Camera &cam) {
        this->cam = cam;
    }

    const Liste<Objet3D> getObjs() const {
        return objs;
    }

    int getHauteur() const {
        return hauteur;
    }

    int getLargeur() const {
        return largeur;
    }

    const Camera getCam() const {
        return cam;
    }
    ObjectScenario(int hauteur, int largeur, Camera &cam, Liste<Lumiere> &lums, Liste<Objet3D> &objs)
            : cam(cam), lums(lums), objs(objs) {
        this->hauteur =hauteur;
        this->largeur = largeur;
    }

    void toImage(char *path, bool outputText, int complexite);
};

class BaseScenario : public ObjectScenario{
public:
    BaseScenario(int hauteur, int largeur);
};

#endif //IMAGE_SCENARIO_HPP
