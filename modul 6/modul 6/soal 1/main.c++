#include <iostream>
#include "Doublylist.h"

using namespace std;

int main() {
    List L;
    address P;
    infotype x;
    CreateList(L);

    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        if (!(cin >> x.thnBuat)) {
            cout << "input tidak valid" << endl;
            return 1;
        }

        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
        }
        cout << endl;
    }

    cout << "DATA LIST 1" << endl << endl;
    printInfo(L);

    cout << endl << "Masukkan Nomor Polisi yang dicari   : ";
    cin >> x.nopol;
    P = findElm(L, x);
    cout << endl;
    if (P != Nil) {
        tampilElm(P);
    } else {
        cout << "Nomor polisi " << x.nopol << " tidak ditemukan" << endl;
    }

    // ===== Soal 3: hapus nomor polisi =====
    cout << endl << "Masukkan Nomor Polisi yang akan dihapus   : ";
    cin >> x.nopol;
    P = findElm(L, x);
    if (P == Nil) {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan." << endl;
    } else {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            deleteAfter(P->prev, P);
        }
        dealokasi(P);
        cout << "Data dengan nomor polisi " << x.nopol << " berhasil dihapus." << endl;
    }

    cout << endl << "DATA LIST 1" << endl << endl;
    printDetail(L);

    return 0;
}