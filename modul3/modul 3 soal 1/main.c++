#include <iostream>
#include <iomanip>
#include "mahasiswa.h"

using namespace std;

int main() {
    mahasiswa data[MAX_MHS];
    int n;

    do {
        cout << "Jumlah mahasiswa (1-" << MAX_MHS << ") : ";
        cin >> n;
    } while (n < 1 || n > MAX_MHS);
    cin.ignore(1000, '\n');

    for (int i = 0; i < n; i++) {
        cout << "\n=== Data Mahasiswa ke-" << i + 1 << " ===" << endl;
        inputMhs(data[i]);
    }

    cout << "\n DAFTAR MAHASISWA " << endl;
    cout << left  << setw(20) << "Nama"
         << setw(12) << "NIM"
         << right
         << setw(8)  << "UTS"
         << setw(8)  << "UAS"
         << setw(8)  << "Tugas"
         << setw(12) << "Nilai Akhir" << endl;
    cout << string(68, '-') << endl;

    for (int i = 0; i < n; i++) {
        tampilMhs(data[i]);
    }

    return 0;
}