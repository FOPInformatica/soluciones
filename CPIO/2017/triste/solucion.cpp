/*
 * https://omegaup.com/arena/problem/triste/
 * 
 * Se observa que el estado final de una persona solo dependerá de si se aplicó un número par o impar
 * de hechizos sobre ella. Si nos fijamos en las k primeras personas , para la persona más a la izquierda
 * ( posición 0 ) esta obsevación se reduce a si aplicamos 0 o 1 vez el hechizo, es decir si esa persona
 * está triste de hecho tenemos que aplicar el hechizo en caso contrario no. Y así podemos repetir este 
 * análisis para las siguientes k personas desde la posición 1, luego desde la posición 2 y así sucesivamente.
 */

#include <iostream>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    for (char &c : s) //feliz valdrá 1 y triste 0
        c = c == 'F' ? 1 : 0;
    int nroHechizos = 0; //número de hechizos
    int i;
    // revisamos el estado de las personas de izquierda a derecha
    for (i = 0; i + k <= s.size(); ++i) { 
        if (not s[i]) { //si la persona está triste tendremos que hacer un hechizo
            for (int j = i; j < i + k; ++j) //intercambiamos estado emocional de k personas
                s[j] = not s[j];
            ++nroHechizos;
        }
    }
    // la cantidad de personas que faltan revisar son < k ya no podemos hacer hechizos
    bool valido = true; 
    for ( ; valido && i < s.size(); ++i) { 
        if (not s[i]) // si alguna persona queda en triste, entonces no hay solución 
            valido = false;
    }
    if (valido)
        cout << nroHechizos;
    else
        cout << -1;
    cout << endl;
}
