#include <bits/stdc++.h>
 
// Algoritmo de Kruskal
// Encontrar a Árvore Geradora Mínima de um grafo
// Complexidade: O(MlogM), com M = número de arestas
 
using namespace std;
 
const int MAXN = 500001;
 
int pai[MAXN], _rank[MAXN];
 
void build(int n){//inicializa o union-find
    for(int i=1;i<=n;++i){
        pai[i] = i;//inicialmente, cada vertice tem sua propria componente (nao temos nenhuma aresta)
        _rank[i] = 0;
    }
}
 
int find_pai(int x){//retorna o pai da componente de x
    if(pai[x]==x)return x;
    return pai[x] = find_pai(pai[x]);
}
 
bool merge(int u,int v){//une os vertices u e v na mesma componente
    int pu = find_pai(u), pv = find_pai(v);
    if(pu==pv)return 0;//se u e v estão na mesma componente, não precisamos unir de novo
    if(_rank[pu]<_rank[pv])swap(pu,pv);
    pai[pv] = pu;
    if(_rank[pu]==_rank[pv])_rank[pu]++;
    return 1;
}

int kruskal(vector<tuple<int,int,int>>arestas,int n){//arestas, qtd de vertices

    build(n);//constroi o union find com n vertices

    sort(arestas.begin(), arestas.end());

    int custo_mst = 0;

    for(auto [custo, u, v] : arestas){
        if(merge(u,v)){//se a uniao foi feita, adiciono o custo da aresta no custo total
            custo_mst += custo;
        }
    }

    return custo_mst;
}
 
int main(){
    int n, m;//numero de vertices, numero de arestas
    cin>>n>>m;

    vector<tuple<int,int,int>>arestas(m);

    for(auto& [custo, u, v] : arestas){//guarda as arestas na ordem (custo_aresta,u,v)
        cin>>u>>v>>custo;
    }

    cout<<kruskal(arestas,n)<<endl;
}