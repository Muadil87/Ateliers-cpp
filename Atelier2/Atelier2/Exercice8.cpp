#include<iostream>
#include<string>
using namespace std;
class Voiture {
public:
	string marque;
	string modele;
	int annee;
	float kilometrage;
	float vitesse;
	void Voiture() {
	}
	void Voiture(string m, string mo, int a, float k, float v) {
		marque = m;
		modele = mo;
		annee = a;
		kilometrage = k;
		vitesse = v;
	}
	void accelerer(float v) {
		vitesse = vitesse + v;
	}
	void freiner(float v) {
		if (vitesse > 0) 
			vitesse -= v;
		vitesse==0;
	}
	void afficher() {
		cout << "Marque: " << marque << endl;
		cout << "Modele: " << modele << endl;
		cout << "Annee: " << annee << endl;
		cout << "Kilometrage: " << kilometrage << endl;
		cout << "Vitesse: " << vitesse << endl;
	}
	void avancer(float distance) {
		kilometrage += distance;
		cout<< "La voiture a avance de " << distance << " km." << endl;
	 
	}
	~Voiture() {
		cout << "Voiture détruite." << endl;
	}
};

int main() {
	Voiture v; 
	v.Voiture("Toyota", "Corolla", 2020, 15000.0, 0.0);
	v.afficher();
	v.accelerer(50.0);
	return 0;
}
