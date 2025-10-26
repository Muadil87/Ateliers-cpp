#include<iostream>
#include<string>
using namespace std;

class Voiture {
private:
    string marque;
    string modele;
    int annee;
    float kilometrage;
    float vitesse;

public:
    Voiture() : marque("Inconnue"), modele("Inconnu"), annee(0), kilometrage(0), vitesse(0) {}
    
    Voiture(string m, string mo, int a, float k, float v) {
        marque = m;
        modele = mo;
        annee = a;
        kilometrage = k;
        vitesse = v;
    }
    
    void accelerer(float v) {
        vitesse += v;
        cout << "Acceleration de " << v << " km/h. Vitesse actuelle: " << vitesse << " km/h" << endl;
    }
    
    void freiner(float v) {
        if (vitesse - v >= 0) {
            vitesse -= v;
            cout << "Freinage de " << v << " km/h. Vitesse actuelle: " << vitesse << " km/h" << endl;
        } else {
            vitesse = 0;
            cout << "La voiture s'est arretee." << endl;
        }
    }
    
    void afficherInfo() {
        cout << "\n=== Informations Voiture ===" << endl;
        cout << "Marque: " << marque << endl;
        cout << "Modele: " << modele << endl;
        cout << "Annee: " << annee << endl;
        cout << "Kilometrage: " << kilometrage << " km" << endl;
        cout << "Vitesse: " << vitesse << " km/h" << endl;
    }
    
    void avancer(float distance) {
        kilometrage += distance;
        cout << "La voiture a avance de " << distance << " km. Kilometrage total: " << kilometrage << " km" << endl;
    }
    
    ~Voiture() {
        cout << "Voiture " << marque << " " << modele << " detruite." << endl;
    }
};

int main() {
    Voiture v1("Toyota", "Corolla", 2020, 15000.0, 0.0);
    v1.afficherInfo();
    v1.accelerer(50.0);
    v1.avancer(100.0);
    v1.freiner(20.0);
    v1.afficherInfo();
    
    return 0;
}