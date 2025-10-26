#include <iostream>
using namespace std;

int main() {
    int taille;
    
    cout << "Entrez la taille du tableau : ";
    cin >> taille;
    
    int* tab1 = new int[taille];
    
    cout << "Entrez " << taille << " nombres entiers : ";
    for (int i = 0; i < taille; i++) {
        cin >> tab1[i];
    }
    
    int* tab2 = new int[taille];
    for (int i = 0; i < taille; i++) {
        tab2[i] = tab1[i] * tab1[i];
    }
    
    delete[] tab1;
    
    cout << "Carres des nombres : ";
    for (int i = 0; i < taille; i++) {
        cout << tab2[i] << " ";
    }
    cout << endl;
    
    delete[] tab2;
    
    return 0;
}