#include <iostream>
using namespace std;

void afficherPermutations(char* chaine, int debut, int fin) {
    if (debut == fin) {
        for (int i = 0; i <= fin; i++) {
            cout << chaine[i];
        }
        cout << endl;
    } else {
        for (int i = debut; i <= fin; i++) {
            char temp = chaine[debut];
            chaine[debut] = chaine[i];
            chaine[i] = temp;
            
            afficherPermutations(chaine, debut + 1, fin);
            
            temp = chaine[debut];
            chaine[debut] = chaine[i];
            chaine[i] = temp;
        }
    }
}

int main() {
    char chaine[100];
    
    cout << "Entrez une chaine de caracteres : ";
    cin >> chaine;
    
    int longueur = 0;
    while (chaine[longueur] != '\0') {
        longueur++;
    }
    
    cout << "\nPermutations possibles :" << endl;
    afficherPermutations(chaine, 0, longueur - 1);
    
    return 0;
}