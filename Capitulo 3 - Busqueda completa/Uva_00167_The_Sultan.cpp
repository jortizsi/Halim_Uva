/* 8 Queens Chess Problem */
#include <cstdlib>                       // we use the int version of 'abs'
#include <cstdio>
#include <cstring>

#include <bits/stdc++.h>

using namespace std;


//____________________________________________________________________
//NOTA: ESTA SOLUCION PARTE DEL CODIGO DE LA PAGINA 88 DEL HALIM
//EN SU EDICION EN ESPANOL, QUE CORRESPONDE A UN PROBLEMA INICIAL
//DE 8 REINAS DONDE SE PIDE USAR O OBLIGATORIAMENTE UNA CASILLA DADA.

//____________________________________________________________________
/*

IDEA DE SOLUCION

Obtener las soluciones al problema de las 8 reinas usando backtracking
y para cada solucion calcular su puntaje almacenando el maximo en todo
momento. Al final del backtracking imprimir el maximo actual.

*/

//____________________________________________________________________



int puntajes[8][8];
int maximo_global = -100000;

int getScore(int* solucion){
    int suma = 0;
    int fila;
    for (int columna =0;columna<8;columna++){
        fila = solucion[columna];
        suma = suma + puntajes[fila][columna];
    }
        return suma;
}

int row[8], TC, a, b, lineCounter;            // ok to use global variables

bool place(int r, int c) {
  for (int prev = 0; prev < c; prev++)    // check previously placed queens
    if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
      return false;        // share same row or same diagonal -> infeasible
  return true; }

void backtrack(int c) {
  if (c == 8) { //solucion posible
                // candidate sol, (a, b) has 1 queen

    int posible_maximo = getScore(row);
    maximo_global = max(maximo_global,posible_maximo);
    //printf("%2d      %d", ++lineCounter, row[0] + 1);
    //for (int j = 1; j < 8; j++) printf(" %d", row[j] + 1);
    //printf("\n");
  }
  for (int r = 0; r < 8; r++)                       // try all possible row
    if (place(r, c)) {          // if can place a queen at this col and row
      row[c] = r; backtrack(c + 1);      // put this queen here and recurse
}   }





int main() {
  scanf("%d", &TC);


  while (TC--) {    //K TestCases o numero de tableros a analizar

    for(int i = 0;i<8;i++){ //por cada fila
            for(int j = 0;j<8;j++){ //leer los puntajes de izquierda a derecha
                scanf("%d",&puntajes[i][j]);
            }
    }

    backtrack(0);           // generate all possible 8! candidate solutions
    printf("%5d\n", maximo_global);
    maximo_global = -100000;
    
}


 } // return 0;
