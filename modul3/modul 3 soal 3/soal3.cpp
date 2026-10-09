#include <iostream>

using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarArray(int A[3][3], int B[3][3], int baris, int kolom) {
    int temp = A[baris][kolom];
    A[baris][kolom] = B[baris][kolom];
    B[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {

    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int x = 100, y = 200;
    int *ptr1 = &x;
    int *ptr2 = &y;

    cout << "=== Array sebelum ditukar ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    int baris, kolom;
    do {
        cout << "\nMasukkan posisi yang ingin ditukar (baris kolom, 0-2) : ";
        cin >> baris >> kolom;
    } while (baris < 0 || baris > 2 || kolom < 0 || kolom > 2);

    tukarArray(A, B, baris, kolom);

    cout << "\n=== Array setelah posisi [" << baris << "][" << kolom
         << "] ditukar ===" << endl;
    cout << "Array A:" << endl;
    tampilArray(A);
    cout << "Array B:" << endl;
    tampilArray(B);

    cout << "\n=== Pointer sebelum ditukar ===" << endl;
    cout << "*ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;

    tukarPointer(ptr1, ptr2);

    cout << "=== Pointer setelah ditukar ===" << endl;
    cout << "*ptr1 = " << *ptr1 << ", *ptr2 = " << *ptr2 << endl;

    return 0;
}