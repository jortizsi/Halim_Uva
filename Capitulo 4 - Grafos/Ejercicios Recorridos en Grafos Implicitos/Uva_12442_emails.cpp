



//Implementación de un grafo dirigido usando su representacion de lista de adyacencia.
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
bool UNVISITED = false;
bool VISITED = true;
bool dfs_num[50001];
bool dfs_num_general[50001];
vector<int> road;
vector<int> * adjList;
int maximos_receptores_correo = -1;
int candidato_maximo = 0;
int DP[50001];


void dfs(int u){//u es el id del nodo donde empezamos el recorrido

    //if(DP[u] > -1){candidato_maximo = candidato_maximo + DP[u];}
    //else{
        dfs_num_general[u] = VISITED;
        dfs_num[u] = VISITED;//Marcamos a u como visitado

        candidato_maximo++;
        //cout<<candidato_maximo<<"\n";

        for(int j = 0; j < (int)adjList[u].size(); j++){//Para cada nodo vecino del vertice u
            int v = adjList[u][j];
            if(dfs_num[v] == UNVISITED){//si lo puedo visitar
                dfs(v);
            }
        }

   // }
}






int main(){

    int testcases;
    scanf("%d",&testcases);


    for (int t=1;t<=testcases;t++){

            maximos_receptores_correo = -1;
            candidato_maximo = 0;

            int n; //Cantidad de nodos en el grafo
            scanf("%d",&n);

            //Usamos arreglo estático de vectores
            adjList = new vector<int>[n+1];//Lista de adyacencia SIN PESO!!!!

            for(int i=0;i<=n;i++){
                dfs_num[i] = UNVISITED;
                DP[i] = -1;
            }

            int solucion;
            for(int i = 1 ;i<=n; i++){

                //Los vertices estan indexados desde cero.

                int marciano_u;
                int marciano_v;
                scanf("%d %d",&marciano_u, &marciano_v);

                adjList[marciano_u].push_back(marciano_v);

            }
            /*
            cout<<"Impresion grafo como lista de adyacencia"<<endl;
            for(int i = 0; i<n; i++){
                cout<<i<<" :";
                for(int j = 0; j<adjList[i].size();j++){
                    cout<<adjList[i].at(j)<<" ";
                }
                cout<<endl;
            }*/


            //Elementos necesarios para la ejecucion de la DFS
            //1)Vector de enteros global -> HECHO
            //2)El grafo a recorrer
            //3)Nodo inicial a expandir o buscar u

            for(int u =1;u<=n;u++){
                if(dfs_num_general[u]== UNVISITED){
                    candidato_maximo = 0;
                    dfs(u);//LA COMPLEJIDAD PARA UNA LISTA DE ADYACENCIA ES O(V+E)
                    //DP[u]= candidato_maximo;
                    //cout<<"desde u "<<u<<" "<<candidato_maximo<<"\n";
                    if(candidato_maximo > maximos_receptores_correo){
                            maximos_receptores_correo = candidato_maximo;
                            solucion = u;
                    }

                    for(int i=0;i<=n;i++){
                        dfs_num[i] = UNVISITED;
                    }
                }
            }
            printf("Case %d: %d\n",t,solucion);
            for(int i=0;i<=n;i++){
                dfs_num_general[i] = UNVISITED;
            }
            delete[] adjList;
            //cout<<"\nmaximo "<<maximos_receptores_correo;
            //cout<<endl;
    }


    return 0;
}
