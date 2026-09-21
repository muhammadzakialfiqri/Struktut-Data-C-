#include <iostream>
using namespace std;

int main() {
    string angka[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan",
        "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas",
        "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"
    };

    int n;

    cout << "Masukkan angka antara 0 - 100 : ";
    cin >> n;

    if (n < 0 || n > 100) {
        cout << "Angka tidak valid. Masukkan angka antara 0 - 100.";
    } else if (n < 20) {
        cout << n << " : " << angka[n];
    } else if (n < 100) {
        cout << n << " : " << angka[n / 10] << " puluh";

        if (n % 10 != 0) {
            cout << " " << angka[n % 10];
        }
    } else {
        cout << n << " : seratus";
    }

    return 0;
}