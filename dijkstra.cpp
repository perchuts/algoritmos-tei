#include <bits/stdc++.h>

// Algoritmo de Dijkstra
// Calcular a distância mínima de um vértice para todos os outros vértices
// Complexidade: O(NlogN), com N = número de vértices

using namespace std;

const int MAXN = 500001;
const int INF = 2e9+1;

vector<pair<int,int>>grafo[MAXN];

int dist[MAXN];

void dijkstra(int origem,int n){

    for(int i=1;i<=n;++i){//distancia pra todos os vertices é desconhecida, exceto pra origem
        dist[i] = INF;
    }

    dist[origem] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;// distancia, vertice

    pq.push({0,origem});

    while(!pq.empty()){

        auto [d, u] = pq.top();
        pq.pop();

        if(dist[u]!=d)continue;//sabemos que existe uma maneira melhor de se chegar em u

        for(auto [custo, v] : grafo[u]){
            
            if(dist[v] > custo + d){//atualiza a distancia de v e adiciona na pq

                dist[v] = custo + d;
                pq.push({dist[v],v});
            }
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=1;i<=m;++i){
        int u, v, custo;
        cin>>u>>v>>custo;
        grafo[u].push_back({custo,v});
        grafo[v].push_back({custo,u});
    }

    dijkstra(1,n);

}