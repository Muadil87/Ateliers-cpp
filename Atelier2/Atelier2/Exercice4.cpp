#include <iostream>
using namespace std;

int main() {
    int taille;
    
    // 1. Allocation du premier tableau
    cout << "Entrez la taille du tableau : ";
    cin >> taille;
    
    int* tab1 = new int[taille];
    
    // Lecture des valeurs
    cout << "Entrez " << taille << " nombres entiers : ";
    for (int i = 0; i < taille; i++) {
        cin >> tab1[i];
    }
    
    // 2. Allocation du deuxième tableau pour les carrés
    int* tab2 = new int[taille];
    
    // Calcul des carrés
    for (int i = 0; i < taille; i++) {
        tab2[i] = tab1[i] * tab1[i];
    }
    
    // 3. Suppression du premier tableau
    delete[] tab1;
    
    // Affichage du deuxième tableau
    cout << "Carrés des nombres : ";
    for (int i = 0; i < taille; i++) {
        cout << tab2[i] << " ";
    }
    cout << endl;
    
    // Suppression du deuxième tableau
    delete[] tab2;
    
    return 0;
}
