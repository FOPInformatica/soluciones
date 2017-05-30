/*
 * https://omegaup.com/arena/problem/Sumas_Multiplo/
 * 
 * Leer primero solucion.cpp
 *
 * Esta solucion tambien usa el "principio del palomar", pero es una
 * implementacion mas lenta.
 * Sabiendo que siempre existe una solucion compuesta de elementos contiguos
 * del arreglo original, probamos todas las subsecuencias posibles hasta
 * encontrar una que de suma multiplo de `N`.
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    for (int i = 0; i < v.size(); ++i) {
        int suma = v[i];
        for (int j = i + 1; j < v.size(); ++j) {
            suma += v[j];
            // `i` es el inicio y `j` es el fin de la subsecuencia.

            if (suma % n == 0) {
                cout << j - i + 1 << endl;
                for (int k = i; k <= j; ++k) {
                    cout << v[k] << ' ';
                }
                cout << endl;
                return 0;
            }
        }
    }
    return 0;
}
