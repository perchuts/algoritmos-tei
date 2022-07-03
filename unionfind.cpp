#include <bits/stdc++.h>
 
// Union-Find
// Unir componentes de um grafo de forma rápida
// Complexidade: O(QlogN), com Q = número de uniões e N = número de vértices
 
using namespace std;
 
const int MAXN = 500001;
 
int pai[MAXN], _rank[MAXN];
 
void build(int n){//inicializa o union-find
    for(int i=1;i<=n;++i){
        pai[i] = i;//inicialmente, cada vertice tem sua propria componente (nao temos nenhuma aresta)
    }
}
 
int find_pai(int x){//retorna o pai da componente de x
    if(pai[x]==x)return x;
    return pai[x] = find_pai(pai[x]);
}
 
void merge(int u,int v){//une os vertices u e v na mesma componente
    int pu = find_pai(u), pv = find_pai(v);
    if(pu==pv)return;//se u e v estão na mesma componente, não precisamos unir de novo
    if(_rank[pu]<_rank[pv])swap(pu,pv);
    pai[pv] = pu;
    if(_rank[pu]==_rank[pv])_rank[pu]++;
}
 
int main(){
    int n;
    cin>>n;
    build(n);
}