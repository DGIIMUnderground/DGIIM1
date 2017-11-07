#include <iostream>

using namespace std;

/**
    @brief Imprime n caracteres en blanco
    @param n: número de caracteres en blanco
*/
void espaciar(int n) {

    for (int i=0; i<n; i++) {
        cout << " ";
    }

}

int main() {

    int n;

    cout << "Introduca la fila n: ";
    cin >> n;
    cout << endl;

    for (int i=0; i<n; i++) {

        espaciar(n-i-1);

        for (int j=i; j>0; j--) {
            cout << j%10;
        }

        cout << 0;

        for (int k=1; k<=i; k++) {
            cout << k%10;
        }

        espaciar(n);

        cout << endl;
    }

}
