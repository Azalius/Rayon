#include <iostream>
#include "../bases3d.hpp"

using namespace std;

int main() {
	Vecteur3D v1 = Vecteur3D(2.0, 2.0, 2.0);
	Vecteur3D v2 = Vecteur3D(2.0, 0.8, -12.0);
	Vecteur3D v3 = Vecteur3D(0.0, 0.0, 2.0);
	Vecteur3D v4 = Vecteur3D(-3.0, -2.0, -0.2);

    Point3D p1 = Point3D(1.0, -2.8, 10.3);
    Point3D p2 = Point3D(0.0,-1.0 , 0.0);


	if (!(v1 + v2 == Vecteur3D(4.0, 2.8, -10.0))) {
		cout << "+1" << endl;
	}
	if (!(v3 + v4 == Vecteur3D(-3.0, -2.0, 1.8))) {
		cout << "+2" << endl;
	}
    if (!(v1 + p2 == Point3D(2.0, 1.0, 2.0))) {
        cout << "+3" << endl;
    }
    if (!(v3 + p1 == Point3D(1.0, -2.8, 12.3))) {
        cout << "+4" << endl;
    }
	if (!(p1 + p2 == Point3D(1.0, -1.8, 10.3))) {
		cout << "+5" << endl;
	}

	if (!(v1 - v2 == Vecteur3D(0.0, 1.2, 14.0))) {
		cout << "-1" << endl;
	}
	if (!(v3 - v4 == Vecteur3D(3.0, 2.0, 2.2))) {
		cout << "-2" << endl;
	}
	if (!(p1 - p2 == Point3D(1.0, -3.8, 10.3))) {
		cout << "-3" << endl;
	}

    if(!(v1*v2) == -92.0/5.0){
        cout << "*" <<endl;
    }



    v3.Normaliser();
    v4.Normaliser();
    float lv4 = 3.61109402;
    if (!(v3 == Vecteur3D(0.0, 0.0, 1.0))){
        cout<<"n1"<<endl;
    }
    if (!(v4 == Vecteur3D(-3.0/lv4, -2.0/lv4, 0.2/lv4))){
        cout<<"n2"<<endl;
    }
}