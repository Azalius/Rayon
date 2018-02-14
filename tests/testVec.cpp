//
// Created by Azalius on 14-Feb-18.
//

#include <array>
#include <iostream>
#include "testVec.hpp"
#include "../bases3d.hpp"

using namespace std;


void TestVec() {
    cout<<"Tests vecteurs : "<<endl;
	Vecteur3D v1 = Vecteur3D(2.0, 2.0, 2.0);
	Vecteur3D v2 = Vecteur3D(2.0, 0.8, -12.0f);
	Vecteur3D v3 = Vecteur3D(0.0, 0.0, 2.0);
	Vecteur3D v4 = Vecteur3D(-3.0f, -2.0f, -0.2f);

    Point3D p1 = Point3D(1.0, -2.8f, 10.3);
    Point3D p2 = Point3D(0.0,-1.0f , 0.0);


	if (!(v1 + v2 == Vecteur3D(4.0, 2.8, -10.0f))) {
		cout << "+1" << endl;
	}
	if (!(v3 + v4 == Vecteur3D(-3.0f, -2.0f, 1.8))) {
		cout << "+2" << endl;
	}
    if (!(v1 + p2 == Point3D(2.0, 1.0, 2.0))) {
        cout << "+3" << endl;
    }
    if (!(v3 + p1 == Point3D(1.0, -2.8f, 12.3))) {
        cout << "+4" << endl;
    }
	if (!(p1 + p2 == Point3D(1.0, -3.8f, 10.3))) {
		cout << "+5" << endl;
	}

	if (!(v1 - v2 == Vecteur3D(0.0, 1.2, 14.0))) {
		cout << "-1" << endl;
	}
	if (!(v3 - v4 == Vecteur3D(3.0, 2.0, 2.2))) {
		cout << "-2" << endl;
	}
	if (!(p1 - p2 == Point3D(1.0, -1.8f, 10.3))) {
		cout << "-3" << endl;
	}
    if (!(-v4 == Vecteur3D(3.0, 2.0, 0.2))) {
        cout << "--" << endl;
    }

    if(!(v1*v2) == -92.0/5.0){
        cout << "*" << endl;
    }
    if(!(v2*3.0 == Vecteur3D(6.0, 2.4, -36.0f))){
        cout << "**" << endl;
    }

    Vecteur3D cross = v2.Cross(v4);
    if(!(cross.X() != 24.16f || cross.Y() != 36.4 || cross.Z() != -1.6f)){
        cout << cross.X() << " " << cross.Y() << " " << cross.Z() << " cross" << endl;
    }
    //reflechir supposé OK

    v3.Normaliser();
    v4.Normaliser();
    if (!(v3 == Vecteur3D(0.0, 0.0, 1.0))){
        cout << "n1" << endl;
    }
    if (!v4.Longueur() == 1){
        cout << "nn" << endl;
    }

    if (v4.X() != -0.830773f || v4.Y()!= 0.553849 || v4.Z()!= -0.0553849f){
        cout << v4.X() << " " << v4.Y() << " " << v4.Z() << " n2" << endl;
    }

    Vecteur3D v5 = Vecteur3D(4.0, 1.0, 1.0);
    Vecteur3D v6 = Vecteur3D(0.0, -2.0f, -1.0f);


    if (!(v5.Refracter(v6, 1.0, 1.5) == Vecteur3D(0.629, 0.661, 0.409))){
        cout << "Refraction" << v5.Refracter(v6, 1.0, 1.5).X() <<" "<< v5.Refracter(v6, 1.0, 1.5).Y() <<" "<< v5.Refracter(v6, 1.0, 1.5).Z() << endl;

    }
}