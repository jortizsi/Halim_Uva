



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
    //obtener el vertice u con stack.top()
    //quitarlo de la pila con stack.pop()
    road.push_back(u);
    dfs_num[u] = VISITED;//Marcamos a u como visitado
    for(int j = 0; j < (int)adjList[u].size(); j++){//Para cada nodo vecino del vertice u
        int v = adjList[u][j];
        if(dfs_num[v] == UNVISITED){//si lo puedo visitar
            dfs(v);
            //Apilo el vertice v en la pila
        }
    }
}

void bfs(int s){//Partimos Tambien de un nodo inicial o fuente OJO SOLO PARA GRAFOS SIN PESO, PERO PUEDEN SER DIRIGIDOS O NO DIRIGIDOS
    queue <int> q;//Declarar cola de nodos puestos
    road.push_back(s);
    dfs_num[s] = VISITED;
    q.push(s);//ponemos nodo fuente en la cola
    while(!q.empty()){//mientras la cola no este vacia
        int u = q.front();//Obtengo primer elemento de la cola
        q.pop();//Ese elemento es sacado de la cola
        for(int j = 0; j < (int)adjList[u].size();j++){//Para cada vecino del vertice u
            int v = adjList[u][j];//vecino de u
            if(dfs_num[v] == UNVISITED){//Si el vertice vecino v no ha sido visitado
                road.push_back(v);//Poner el vertice vecino en el camino de expansion
                q.push(v); //Ponerlo en la cola
                dfs_num[v] = VISITED;
            }
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
    cout<<"El Recorrido del grafo usando DFS es: "<<endl;
    dfs(u);//LA COMPLEJIDAD PARA UNA LISTA DE ADYACENCIA ES O(V+E)
    for(int k = 0; k<road.size();k++){
        cout<<road[k]<<" ";
    }
    cout<<endl;
    road.clear();
    for(int i = 0; i<dfs_num.size();i++){//Inicializamos nuevamente el arreglo de visitados a todos no visitados.
        dfs_num[i] = UNVISITED;
    }
    bfs(u);//LA COMPLEJIDAD PARA UNA LISTA DE ADYACENCIA ES O(V+E)
    cout<<"El Recorrido del grafo usando BFS es: "<<endl;
    for(int k = 0; k<road.size();k++){
        cout<<road[k]<<" ";
    }
    cout<<endl;
    delete[] adjList;
    return 0;
}
