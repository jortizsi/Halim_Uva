



//Implementación de un grafo dirigido usando su representacion de lista de adyacencia.
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
bool UNVISITED = false;
bool VISITED = true;
vector<bool> dfs_num;
vector<int> road;
vector<int> * adjList;

void dfs(int u){//OJO, u es el id del nodo donde empezamos el recorrido
    road.push_back(u);
    dfs_num[u] = VISITED;//Marcamos a u como visitado
    for(int j = 0; j < (int)adjList[u].size(); j++){//Para cada nodo vecino del vertice u
        int v = adjList[u][j];
        if(dfs_num[v] == UNVISITED){//si lo puedo visitar
            dfs(v);
        }
    }
}

int main(){
    int n; //Cantidad de nodos en mi grafo
    scanf("%d",&n);
    //Usamos arreglo estático de vectores
    adjList = new vector<int>[n];//Lista de adyacencia SIN PESO!!!!
    for(int i = 0 ;i<n; i++){//Los vertices estan indexados desde cero.
        cout<<"Digite el identificador del nodo a ingresar entre estos valores: "<<0<<" a "<<n-1<<endl;
        cout<<"Digite -1 para detenerse"<<endl;
        int nodeId;
        scanf("%d",&nodeId);
        while(nodeId != -1 && nodeId >= 0 && nodeId <= n-1){
            adjList[i].push_back(nodeId);
            scanf("%d",&nodeId);
        }
        sort(adjList[i].begin(),adjList[i].end());
        dfs_num.push_back(UNVISITED);
    }
    cout<<"Impresion grafo como lista de adyacencia"<<endl;
    for(int i = 0; i<n; i++){
        cout<<i<<" :";
        for(int j = 0; j<adjList[i].size();j++){
            cout<<adjList[i].at(j)<<" ";
        }
        cout<<endl;
    }
    //Elementos necesarios para la ejecucion de la DFS
    //1)Vector de enteros global -> HECHO
    //2)El grafo a recorrer
    //3)Nodo inicial a expandir o buscar u
    cout<<"Ingrese el id del nodo raiz u para ejecutar dfs sobre el"<<endl;
    cout<<"Entre 0 y "<<n-1<<endl;
    int u;
    scanf("%d",&u);
    dfs(u);//LA COMPLEJIDAD PARA UNA LISTA DE ADYACENCIA ES O(V+E)
    for(int k = 0; k<road.size();k++){
        cout<<road[k]<<" ";
    }
    cout<<endl;
    delete[] adjList;
    return 0;
}
