#include <iostream>
using namespace std;

void remplir(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Entrer l'element " << i + 1 << " : ";
        cin >> *(arr + i);
    }
}

void afficher(const int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

int& trouverMax(int* arr, int n) {
    int count = 0;
    for (int i = 1; i < n; i++)
        if (*(arr + i) > *(arr + count))
            count = i;
    return *(arr + count);
}

void inverser(int* arr, int n) {
    int* debut = arr;           // Pointeur vers premier élément
    int* fin = arr + n - 1;     // Pointeur vers dernier élément
    
    while (debut < fin) {       // Continue tant que debut avant fin
        // ÉCHANGE les valeurs pointées
        int temp = *debut;      // Garde valeur de debut dans temp
        *debut = *fin;          // Met valeur de fin à la place debut
        *fin = temp;            // Met ancienne valeur debut à fin
        
        // DÉPLACE les pointeurs
        debut++;  // Va vers la droite
        fin--;    // Va vers la gauche
    }
}
int main() {
    int n;
    cout << "Entrer la taille du tableau : ";
    cin >> n;
    
    int* arr = new int[n];
    remplir(arr, n);
    
    cout << "Tableau original : ";
    afficher(arr, n);
    
    int& max = trouverMax(arr, n);
    cout << "Maximum = " << max << endl;
    
    // Modification automatique du maximum via la référence
    max += 10;
    cout << "Après modification du maximum (+10) : ";
    afficher(arr, n);
    
    inverser(arr, n);
    cout << "Tableau inversé : ";
    afficher(arr, n);
    
    delete[] arr;
    return 0;

}
