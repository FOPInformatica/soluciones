/**
 * C. Estaciones espaciales
 * https://omegaup.com/arena/problem/Estaciones-Espaciales#problems
 *
 * Para este problema representaremos las estaciones como vertices de un grafo
 * y los tuneles que conectan 2 estaciones como las aristas del grafo, 
 * entonces necesitamos encontrar el tamano de la menor cobertura por vertices.
 * (ver aqui: https://es.wikipedia.org/wiki/Cobertura_de_v%C3%A9rtices)
 *
 * Un dato importante del problema es que solo existe un camino entre dos estaciones, lo que
 * hace que el grafo sea en realidad un arbol. La ventaja de trabajar con un arbol es que 
 * tiene una cantidad de aristas reducida comparada con un grafo normal, de hecho 
 * la cantidad de aristas es igual a la cantidad de vertices menos 1.
 * (ver aqui: https://en.wikipedia.org/wiki/Tree_%28graph_theory%29)
 *
 * Un primer algoritmo para este problema es probar todas las posible configuraciones, 
 * que para 15 vertices es factible. Generar todas las posibles configuraciones,
 * comenzando por aquellas que tienen menor cantidad de vertices, toma 
 * tiempo O(2^n) y verificar cada una es lineal, por tanto esta solucion tiene complejidad O(2^n).
 *
 * Sin embargo, para 10^5 vertices, el algoritmo anterior tomaria mucho tiempo. Por ello,
 * para resolver este problema usaremos un algoritmo de programacion dinamica.
 * Definimos una variable "usados" que indica la cantidad de agentes usados hasta el momento,
 * luego, definimos la cantidad de agentes requeridos DP[v][0] como la cantidad de agentes usados
 * si el presente vertice tiene un agente y DP[v][1] como la cantidad de agentes usados si el presente 
 * vertices NO tiene un agente; finalmente guardamos el menor de ellos para la siguiente iteracion
 * en DP[v][1].
 * Hacemos un abordaje bottom-up. Finalmente la solucion sera DP[0][1].
 * Podemos comenzar en cualquier vertice pues podemos enraizar el arbol en cualquier vertice.
 *
 * Llenar la tabla toma tiempo lineal; entonces la complejidad es O(n).
 */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);	//Grafo G
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        G[x - 1].push_back(i);
    }
    vector<vector<int>> DP(n, vector<int>(2));	//tabla con el numero de agentes requeridos 
    for (int u = n - 1; u >= 0; --u) {		//iteracion bottom-up 
        int usados[] = {0, 0};
        for (int v : G[u]) {			//recorremos los vertices adyacentes a u y acumulamos la cantidad de agentes usados hasta el momento en la variable usados
            usados[0] += DP[v][0];
            usados[1] += DP[v][1];
        }
        DP[u][0] = 1 + usados[1];			// adicionamos un agente para el actual vertice
        DP[u][1] = min(1 + usados[1], usados[0]);	// menor numero de agentes requeridos hasta el vertice u
    }
    cout << DP[0][1] << endl;
}
