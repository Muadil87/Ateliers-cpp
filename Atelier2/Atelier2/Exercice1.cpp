#include<iostream>
using namespace std;

bool estPair(int n) {
    return n % 2 == 0;
}

bool estMultipleDe3(int n) {
    return n % 3 == 0;
}

int main() {
    int nombre;
    cout << "entrer un nombre entier : ";
    cin >> nombre;
    
    if (estPair(nombre))
        cout << "il est pair" << endl;
    
    if (estMultipleDe3(nombre))
        cout << "il est multiple de 3" << endl;
    
    if (estPair(nombre) && estMultipleDe3(nombre))
        cout << "il est divisible par 6" << endl;
    
    return 0;
}