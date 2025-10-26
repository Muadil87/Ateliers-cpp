#include <iostream>
#include <cmath>
using namespace std;

class NombreComplexe {
private:
    float reel;
    float imaginaire;

public:
    NombreComplexe(float r = 0, float i = 0) : reel(r), imaginaire(i) {}
    
    void afficher() {
        if (imaginaire >= 0)
            cout << reel << " + " << imaginaire << "i";
        else
            cout << reel << " - " << -imaginaire << "i";
    }
    
    NombreComplexe addition(const NombreComplexe& c) {
        return NombreComplexe(reel + c.reel, imaginaire + c.imaginaire);
    }
    
    NombreComplexe soustraction(const NombreComplexe& c) {
        return NombreComplexe(reel - c.reel, imaginaire - c.imaginaire);
    }
    
    NombreComplexe multiplication(const NombreComplexe& c) {
        float r = reel * c.reel - imaginaire * c.imaginaire;
        float i = reel * c.imaginaire + imaginaire * c.reel;
        return NombreComplexe(r, i);
    }
    
    NombreComplexe division(const NombreComplexe& c) {
        float denom = c.reel * c.reel + c.imaginaire * c.imaginaire;
        if (denom == 0) {
            cout << "Erreur: Division par zero!" << endl;
            return NombreComplexe(0, 0);
        }
        float r = (reel * c.reel + imaginaire * c.imaginaire) / denom;
        float i = (imaginaire * c.reel - reel * c.imaginaire) / denom;
        return NombreComplexe(r, i);
    }
    
    bool egalite(const NombreComplexe& c) {
        return (reel == c.reel && imaginaire == c.imaginaire);
    }
};

void afficherMenu() {
    cout << "\n=== CALCULATRICE NOMBRES COMPLEXES ===" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Soustraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Egalite" << endl;
    cout << "6. Quitter" << endl;
    cout << "Votre choix: ";
}

int main() {
    float r1, i1, r2, i2;
    int choix;
    
    do {
        cout << "\n--- Premier nombre complexe ---" << endl;
        cout << "Partie reelle: ";
        cin >> r1;
        cout << "Partie imaginaire: ";
        cin >> i1;
        
        cout << "\n--- Deuxieme nombre complexe ---" << endl;
        cout << "Partie reelle: ";
        cin >> r2;
        cout << "Partie imaginaire: ";
        cin >> i2;
        
        NombreComplexe c1(r1, i1);
        NombreComplexe c2(r2, i2);
        NombreComplexe resultat;
        
        cout << "\nNombres saisis:" << endl;
        cout << "c1 = "; c1.afficher(); cout << endl;
        cout << "c2 = "; c2.afficher(); cout << endl;
        
        afficherMenu();
        cin >> choix;
        
        switch(choix) {
            case 1:
                resultat = c1.addition(c2);
                cout << "Addition: "; c1.afficher(); cout << " + "; c2.afficher();
                cout << " = "; resultat.afficher(); cout << endl;
                break;
            case 2:
                resultat = c1.soustraction(c2);
                cout << "Soustraction: "; c1.afficher(); cout << " - "; c2.afficher();
                cout << " = "; resultat.afficher(); cout << endl;
                break;
            case 3:
                resultat = c1.multiplication(c2);
                cout << "Multiplication: "; c1.afficher(); cout << " * "; c2.afficher();
                cout << " = "; resultat.afficher(); cout << endl;
                break;
            case 4:
                resultat = c1.division(c2);
                cout << "Division: "; c1.afficher(); cout << " / "; c2.afficher();
                cout << " = "; resultat.afficher(); cout << endl;
                break;
            case 5:
                cout << "Egalite: "; c1.afficher(); cout << " et "; c2.afficher();
                cout << " sont " << (c1.egalite(c2) ? "EGAUX" : "DIFFERENTS") << endl;
                break;
            case 6:
                cout << "Au revoir!" << endl;
                break;
            default:
                cout << "Choix invalide!" << endl;
        }
        
    } while (choix != 6);
    
    return 0;
}