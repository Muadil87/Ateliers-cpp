#include <iostream>
using namespace std;

void afficherPermutations(char* chaine, int debut, int fin) {
    if (debut == fin) {
        // Afficher la permutation actuelle
        for (int i = 0; i <= fin; i++) {
            cout << chaine[i];
        }
        cout << endl;
    } else {
        // Générer toutes les permutations
        for (int i = debut; i <= fin; i++) {
            // Échanger le caractère courant avec celui en position début
            char temp = chaine[debut];
            chaine[debut] = chaine[i];
            chaine[i] = temp;
            
            // Appel récursif pour le reste de la chaîne
            afficherPermutations(chaine, debut + 1, fin);
            
            // Restaurer l'ordre original (backtracking)
            temp = chaine[debut];
            chaine[debut] = chaine[i];
            chaine[i] = temp;
        }
    }
}

int main() {
    char chaine[100];
    
    cout << "Entrez une chaîne de caractères : ";
    cin >> chaine;
    
    // Calculer la longueur de la chaîne
    int longueur = 0;
    while (chaine[longueur] != '\0') {
        longueur++;
    }
    
    cout << "\nPermutations possibles :" << endl;
    afficherPermutations(chaine, 0, longueur - 1);
    
    return 0;
}
