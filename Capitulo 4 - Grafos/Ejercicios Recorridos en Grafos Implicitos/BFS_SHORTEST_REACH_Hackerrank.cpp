

//Implementación de grafo como lista de adyacencia. :D Gracias Universidad Nacional Por todo, Perdon profe Andres por Subir el codigo tarde, Implementación de BFS Tomada del libro: Competitive Programming de FELIX HALIM y STEVEN HALIM.

//Solucion a problema https://www.hackerrank.com/contests/ds-2019-taller-iv/challenges/bfsshortreach/problem
//Nombre del problema: BFS Shortest Reach
/*Descripcion del problema
Dado un grafo no dirigido con pesos de 6 en cada arista, hacer un programa que reporte
la distancia mínima desde un nodo de origen S dado en el input.
El resultado puede Obtenerse mediante BFS
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> * adjList;
vector<int> d2;

void bfs(int s){//Partimos Tambien de un nodo inicial o fuente OJO SOLO PARA GRAFOS SIN PESO, PERO PUEDEN SER DIRIGIDOS O NO DIRIGIDOS
    d2[s] = 0;
    queue <int> q;//Declarar cola de nodos puestos
    queue <int> depth;
    q.push(s);//ponemos nodo fuente en la cola
    depth.push(0);
    while(!q.empty()){//mientras la cola no este vacia
        int u = q.front();//Obtengo primer elemento de la cola
        int deep = depth.front();
        q.pop();//Ese elemento es sacado de la cola
        depth.pop();
        for(int j = 0; j < (int)adjList[u].size();j++){//Para cada vecino del vertice u
            int v = adjList[u][j];//vecino de u
            if(d2[v] == -1){//Si el vertice vecino v no ha sido visitado
                d2[v] = (deep+6);
                depth.push(deep+6);
                q.push(v); //Ponerlo en la cola
            }
        }
    }

}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int q;
    while(scanf("%d",&q) != EOF){//mientras la cantidad de consultas sea distinta de cero o EOF
        for(int i = 0; i<q; i++){//PARA CADA CONSULTA
            int v,e;//DECLARAR CANTIDAD DE VERTICES Y ARISTAS
        scanf("%d %d",&v,&e);//LEER VERTICES Y ARISTAS
        adjList = new vector<int>[v+1];//CREAR LISTA DE ADYACENCIA CON UN ELEMENTO MAS YA QUE GRAFO INDEXADO-1
        for(int i = 0; i<e; i++){//PARA LA CANTIDAD DE VERTICES
            int u,v;//DECLARO VERTICE U ORIGEN Y VERTICE V DE DESTINO
            scanf("%d %d",&u,&v);//LEO CADA VERTICE
            adjList[u].push_back(v);//PONGO CAMINO DE IDA
            adjList[v].push_back(u);//PONGO CAMINO DE REGRESO
        }
        for(int i = 1; i<=v; i++){
            sort(adjList[i].begin(),adjList[i].end());//ORDENO LOS VERTICES ADYACENTES AL NODO I
        }
        int s;//DECLARO ID DEL NODO FUENTE
        scanf("%d",&s);//LEO LA FUENTE
        vector<int> d(v+1,-1);//CREO VECTOR DE DISTANCIAS DE TAMAÑO TAMBIEN MAYOR A 1
        d2 = d;
        bfs(s);//BUSQUEDA EN PROFUNDIDAD DESDE LA FUENTE
        for(int i = 1;i<(int)d2.size();i++){
            if(i != s){
                printf("%d ",d2[i]);
           }
        }
        printf("\n");
        d2.clear();
        adjList->clear();
        }
    }
    return 0;
}
