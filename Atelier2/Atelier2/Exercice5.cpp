#include <iostream>
using namespace std;

// Version avec pointeurs (style C)
void incrementer_pointeur(int* x) {
    (*x)++;
}

void permuter_pointeur(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Version avec références (style C++)
void incrementer_reference(int& x) {
    x++;
}

void permuter_reference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    cout << "=== Version avec pointeurs ===" << endl;
    int x = 5, y = 10;
    cout << "Avant : x = " << x << ", y = " << y << endl;
    
    incrementer_pointeur(&x);
    permuter_pointeur(&x, &y);
    cout << "Apres : x = " << x << ", y = " << y << endl;
    
    cout << "\n=== Version avec references ===" << endl;
    int a = 5, b = 10;
    cout << "Avant : a = " << a << ", b = " << b << endl;
    
    incrementer_reference(a);
    permuter_reference(a, b);
    cout << "Apres : a = " << a << ", b = " << b << endl;
    
    return 0;
}