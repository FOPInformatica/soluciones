/*
 * https://omegaup.com/arena/problem/Sumas_Multiplo/
 * 
 * Este problema permite que mostremos cualquier solucion. Una solucion
 * inmediata seria intentar todos los subconjuntos posibles, bien
 * usando funciones recursivas para implementar la tecnica "backtracking"
 * o usando "mascaras de bits". Esa solucion basta para obtener 20 puntos.
 *
 * Sin embargo, se puede demostrar que existe una solucion compuesta por
 * elementos contiguos en el arreglo. Esto es gracias al "principio del
 * palomar". Consideremos las sumas parciales de todos los prefijos
 * de un arreglo. Por ejemplo, dado el arreglo de tamaño N=5:
 * 1 2 3 4 1
 * Las sumas parciales son 1 3 6 10 11
 * Ahora, tomemos el residuo respecto a 5: 1 3 1 0 1
 * En este caso, observamos que hay un 0. Lo cual quiere decir que el
 * subconjunto contiguo que empieza en el inicio y termina donde está el 0
 * es una solución.
 *
 * Ahora Supongamos que no hay 0s. Entonces las sumas parciales residuales
 * solo pueden tomar valores de `1` a `N-1`. Por el "principio del palomar"
 * nos damos cuenta que al menos existen 2 valores que se repiten (tenemos
 * `N` palomas que son las `N` sumas residuales y solo `N-1` nidos).
 * 
 * Ahora bien, para que una suma residual se repita, hay que sumar un
 * numero multiplo de `N`. Por tanto, los numeros que estan entre las
 * posiciones de las sumas parciales residuales iguales, suman un numero
 * multiplo de `N`.
 *
 * En el ejemplo, tenemos 1s en las posiciones 1, 3 y 5. Entonces, son
 * soluciones los conjuntos que van de las posiciones:
 * - 2 a 3: 2 + 3
 * - 2 a 5: 2 + 3 + 4 + 1
 * - 4 a 5: 4 + 1
 *
 * Pero, basta solo mostrar una solucion, la primera que encontremos.
 *
 * Enlaces útiles:
 * - https://es.wikipedia.org/wiki/Principio_del_palomar
 * - https://es.wikipedia.org/wiki/Vuelta_atr%C3%A1s
 * - https://es.wikipedia.org/wiki/M%C3%A1scara_(inform%C3%A1tica)
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int suma = 0;
    vector<int> v(n);

    // `posicion[i]` almacenara la posicion donde se encontro la suma
    // residual de valor `i`.
    // -1 indica que aun no se encontro ninguna.
    vector<int> posicion(n, -1);

    for (int &x : v)
        cin >> x;

    // Por simplicidad, asumimos que la suma residual de valor 0
    // es la de la suma de los 0 primeros elementos.
    posicion[0] = 0;

    int i;
    for (i = 0; i < v.size(); ++i) {
        suma = (suma + v[i]) % n;  // Suma acumulada.
        if (posicion[suma] != -1)
            break;  // Detenemos si hemos visto la suma antes.
        posicion[suma] = i + 1;  // Almacenamos la posicion de la suma.
    }

    // `posicion[suma]` contiene el primer elemento e `i` contiene el
    // ultimo.
    cout << (i - posicion[suma] + 1) << endl;
    for (int j = posicion[suma]; j <= i; ++j)
        cout << v[j] << ' ';
    cout << endl;
    return 0;
}
