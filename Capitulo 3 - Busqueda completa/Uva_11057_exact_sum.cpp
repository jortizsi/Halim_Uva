#include <iostream>
#include <bits/stdc++.h>

using namespace std;



//_____________________________________________________________________________________________________________
//BUSQUEDA BINARIA

//ADAPTADO DE GeeksforGeeks
//https://www.geeksforgeeks.org/c-program-for-binary-search-recursive-and-iterative/

//Estas versiones de busqueda binaria reciben un indice prohibido
//que se usa para buscar que un valor este en la lista y que sea posible
//encontrarlo en un indice distinto al prohibido. Esto es util para
//el problema tratado.

//La version iterativa es mas eficiente que la recursiva





// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int busqueda_binaria(vector<int> lista, int limite_izquierdo, int limite_derecho, int valor_buscado, int indice_prohibido)
{
   if (limite_derecho >= limite_izquierdo)
   {
        int mitad = (int)(limite_izquierdo + ((limite_derecho - limite_izquierdo)/2));

        // If the element is present at the middle itself
        if (lista[mitad] == valor_buscado && mitad != indice_prohibido){ return mitad;}

        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (lista[mitad] > valor_buscado){ return busqueda_binaria(lista, limite_izquierdo, mitad-1, valor_buscado, indice_prohibido);}

        // Else the element can only be present in right subarray
        return busqueda_binaria(lista, mitad+1, limite_derecho, valor_buscado, indice_prohibido);
   }

   // We reach here when element is not present in array
   return -1;
}



// A iterative binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int busqueda_binaria_iterativa(vector<int> arr, int l, int r, int x,int forbidden_index)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;

    // Check if x is present at mid
    if (arr[m] == x && m != forbidden_index)
        return m;

    // If x greater, ignore left half
    if (arr[m] < x)
        l = m + 1;

    // If x is smaller, ignore right half
    else
         r = m - 1;
  }

  // if we reach here, then element was not present
  return -1;
}

//_____________________________________________________________________________________________________________



/*

Explicacion de la solucion


Se desea verificar que en una lista ordenada existan dos numeros a y b que sumen un valor c.

La solucion consiste en que para cada numero a en la lista se revisa si existe tambien
un valor  b = c-a, tal que a+b=c.

Se iteran por los n numeros de la lista y se hace busqueda binaria para cada valor
del numero que hace falta para completar el valor total deseado.

Usando un indice prohibido se valida que no se tome un mismo libro dos veces.

La complejidad se estima asi en O(n*Logn).

*/

int* libros_a_comprar(vector<int> precio, int presupuesto){
    static int respuesta[2];
    int diferencia_minima = 100000000;
    int ultimo_indice = precio.size() - 1;

    for(int i=0; i<=ultimo_indice; i++){

        int valor_buscado = presupuesto - precio[i];
        int bb = busqueda_binaria_iterativa(precio, 0, ultimo_indice, valor_buscado, i);

        if(bb != -1){

            int diferencia = abs(precio[i]-valor_buscado);
            if(diferencia  < diferencia_minima){
                diferencia_minima = diferencia;
                respuesta[0] = precio[i];
                respuesta[1] = valor_buscado;
            }
        }

    }
    sort(respuesta, respuesta + 2);
    return respuesta;
}





int main()
{

    int libros;
    int presupuesto;
    int leido;

    vector<int> precio;


    while(scanf("%d",&libros)!= EOF){

            for(int i = 0; i<libros; i++){
                scanf("%d",&leido);
                precio.push_back(leido);
            }
            scanf("%d",&presupuesto);

            sort(precio.begin(), precio.end());

            int* solucion = libros_a_comprar(precio, presupuesto);
            printf("Peter should buy books whose prices are %d and %d.\n\n", solucion[0], solucion[1]);

            precio.clear();

    }



    return 0;
}
