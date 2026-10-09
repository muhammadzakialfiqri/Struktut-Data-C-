#include <iostream>
#include <iomanip>
#include "mahasiswa.h"

using namespace std;

float hitungNilaiAkhir(mahasiswa m) {
    return 0.3f * m.uts + 0.4f * m.uas + 0.3f * m.tugas;
}

void inputMhs(mahasiswa &m) {
    cout << "Nama   : ";
    getline(cin, m.nama);
    cout << "NIM    : ";
    getline(cin, m.nim);
    cout << "UTS    : ";
    cin >> m.uts;
    cout << "UAS    : ";
    cin >> m.uas;
    cout << "Tugas  : ";
    cin >> m.tugas;
    cin.ignore(1000, '\n'); 

    m.nilaiAkhir = hitungNilaiAkhir(m);
}

void tampilMhs(mahasiswa m) {
    cout << left  << setw(20) << m.nama
         << setw(12) << m.nim
         << right << fixed << setprecision(2)
         << setw(8) << m.uts
         << setw(8) << m.uas
         << setw(8) << m.tugas
         << setw(12) << m.nilaiAkhir << endl;
}