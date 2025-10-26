#include<iostream>
using namespace std;
int multiple2(int n) {
	if (n % 2 == 0) {
		return 1;
	}
	else return 0;

}
int multiple3(int n) {
	if (n % 3 == 0)
		return 1;
	else
		return 0;
}
int main() {
	int n, n2, n3;
	cout << "entrer un nombre entier :";
	cin >> n;
	n2 = multiple2(n);
	n3 = multiple3(n);
	if (n2 == 1)
		cout << "il est paire" << endl;
    if (n3 == 1) 
		cout << "il est multiple de 3" << endl;
	
	if (n2 == 1 && n3 == 1)
		cout << "il est divisible par 6" << endl;
	return 0;
}
