#include <iostream>
using namespace std;

int main() {
    const int TAILLE = 10;
    int tab[TAILLE];
    
    // Lecture
    cout << "Entrez " << TAILLE << " nombres entiers : ";
    for (int i = 0; i < TAILLE; i++) {
        cin >> tab[i];
    }
    
    // Recherche min et max
    int min = tab[0];
    int max = tab[0];
    
    for (int i = 1; i < TAILLE; i++) {
        if (tab[i] < min) min = tab[i];
        if (tab[i] > max) max = tab[i];
    }
    
    cout << "Plus petit : " << min << endl;
    cout << "Plus grand : " << max << endl;
    
    return 0;
}
}
