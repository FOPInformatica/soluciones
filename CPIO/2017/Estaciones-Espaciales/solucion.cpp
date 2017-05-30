/**
 * C. Estaciones espaciales
 * https://omegaup.com/arena/problem/Estaciones-Espaciales#problems
 * Si representamos una estacion como un vertice de un grafo, y los tuneles que las conectan como una 
 * arista del grafo, entonces necesitamos encontrar el tamano de la menor covertura por vertices.
 * El hecho que exista solo un camino entre dos vertices hace que el grafo sea un arbol.
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
    vector<vector<int>> DP(n, vector<int>(2));	//tabla con el numero de agentes requeridos para cada arbol
    for (int u = n - 1; u >= 0; --u) {		//iteracion bottom-up 
        int taken[] = {0, 0};
        for (int v : G[u]) {
            taken[0] += DP[v][0];
            taken[1] += DP[v][1];
        }
        DP[u][0] = 1 + taken[1];		
        DP[u][1] = min(1 + taken[1], taken[0]);	//numero de agentes requeridos
    }
    cout << DP[0][1] << endl;
}
