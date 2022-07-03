#include <bits/stdc++.h>
 
// BFS
// Visita os vértices em ordem de distância para a origem
// Complexidade: O(N+M), com N = número de vértices e M = número de arestas
 
using namespace std;
 
const int MAXN = 500001;
 
vector<int>grafo[MAXN];
 
bool visitado[MAXN];
 
void bfs(int origem){
    queue<int>fila;
    fila.push(origem);
 
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
 
        for(auto v:grafo[u]){
            if(!visitado[v]){
 
                visitado[v] = 1;
                fila.push(v);
            }
        }
    }
}   
 
int main(){
    int n, m;//n = quantidade de vértices, m = quantidade de arestas
    
    cin>>n>>m;
 
    for(int i=1;i<=m;++i){
        int u,v;
        cin>>u>>v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);//se a aresta é direcionada, apague essa linha
    }
   
    for(int i=1;i<=n;++i){
        if(visitado[i]==0){
            bfs(i);
        }
    }
 
}