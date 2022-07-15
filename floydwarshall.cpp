#include <bits/stdc++.h>

// Algoritmo de Floyd-Warshall
// Encontrar a distância mínima entre todo par de vértices
// Complexidade: O(N^3), com N = número de vértices

using namespace std;

const int MAXN = 401;
const int INF = 1e9+1;

int dist[MAXN][MAXN];

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j)dist[i][j] = 0;//distancia de mim pra mim mesmo é sempre zero
            else dist[i][j] = INF;//não sabemos se é possível ir de i pra j
        }
    }

    for(int i=1;i<=m;++i){
        int u, v, custo;
        cin>>u>>v>>custo;
        
        dist[u][v] = dist[v][u] = custo;
    }

    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
}