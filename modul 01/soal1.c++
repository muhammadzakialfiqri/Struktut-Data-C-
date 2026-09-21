#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int a,b ;

	cout << "masukan nilai a : ";
	cin >> a;
	cout << "masukan nilai b : ";
	cin >> b;

	cout << "hasil penjumlahan (" << a << " + " << b << ") : " << a + b << endl;
	cout << "hasil pengurangan (" << a << " - " << b << ") : " << a - b << endl;
	cout << "hasil perkalian (" << a << " * " << b << ") : " << a * b << endl;
	cout << "hasil pembagian (" << a << " / " << b << ") : " << a / b << endl;
	

	return 0;
}