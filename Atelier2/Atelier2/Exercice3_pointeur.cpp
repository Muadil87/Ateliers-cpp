#include <iostream>
using namespace std;

int main() {
    const int TAILLE = 10;
    int tab[TAILLE];
    
    // Lecture avec pointeurs
    cout << "Entrez " << TAILLE << " nombres entiers : ";
    for (int* p = tab; p < tab + TAILLE; p++) {
        cin >> *p;
    }
    
    // Recherche min et max avec pointeurs
    int* p_min = tab;
    int* p_max = tab;
    
    for (int* p = tab + 1; p < tab + TAILLE; p++) {
        if (*p < *p_min) p_min = p;
        if (*p > *p_max) p_max = p;
    }
    
    cout << "Plus petit : " << *p_min << endl;
    cout << "Plus grand : " << *p_max << endl;
    
    return 0;
}
