#include<iostream>
#include<cmath>
using namespace std;

class Vecteur3D {
private:
    float x, y, z;

public:
    Vecteur3D(float a = 0, float b = 0, float c = 0) : x(a), y(b), z(c) {}
    
    void afficher() {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }
    
    Vecteur3D somme(const Vecteur3D& v) {
        return Vecteur3D(x + v.x, y + v.y, z + v.z);
    }
    
    float produitScalaire(const Vecteur3D& v) {
        return x * v.x + y * v.y + z * v.z;
    }
    
    bool coincide(const Vecteur3D& v) {
        return (x == v.x && y == v.y && z == v.z);
    }
    
    float norme() {
        return sqrt(x*x + y*y + z*z);
    }
    
    Vecteur3D normax(Vecteur3D& v) {
        if (this->norme() > v.norme()) {
            return *this;
        } else {
            return v;
        }
    }
};

int main() {
    Vecteur3D v1(1, 2, 3);
    Vecteur3D v2(4, 5, 6);
    
    cout << "Vecteur 1: ";
    v1.afficher();
    
    cout << "Vecteur 2: ";
    v2.afficher();
    
    Vecteur3D somme = v1.somme(v2);
    cout << "Somme: ";
    somme.afficher();
    
    cout << "Produit scalaire: " << v1.produitScalaire(v2) << endl;
    
    cout << "Coincident: " << (v1.coincide(v2) ? "Oui" : "Non") << endl;
    
    cout << "Norme v1: " << v1.norme() << endl;
    cout << "Norme v2: " << v2.norme() << endl;
    
    Vecteur3D plusGrand = v1.normax(v2);
    cout << "Vecteur avec la plus grande norme: ";
    plusGrand.afficher();
    
    return 0;
}