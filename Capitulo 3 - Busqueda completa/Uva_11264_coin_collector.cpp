#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int leido;
    int testcases;
    int denominaciones;
    vector<int> valores;
    int total;
    int solucion;



    scanf("%d",&testcases);

    for(int t =0; t<testcases; t++){

        scanf("%d",&denominaciones);
        for(int j = 0; j<denominaciones; j++){
                scanf("%d",&leido);
                valores.push_back(leido);
            }

        //------------------------------------------------------//

        /*

        SOLUCION VORAZ (Greedy)

        se van seleccionando numeros de la lista de menor a mayor.

        La validacion a hacer para una denominacion i es que el valor
        de i+1 sea  mayor que el subtotal de los anteriores.

        Si esto no se cumple, entonces no se puede tomar la denominacion i
        en tanto que el acumulado obtenido se puede reemplazar total o
        parcialmente por un numero mas grande, de forma que no se usan
        monedas de valor i.

        */


        total = 0;
        solucion = 1;

        for(int i=0; i<(denominaciones-1); i++){
            if(valores[i+1] > (valores[i] + total)){
               total += valores[i];
               solucion++;
               }
        }

        //------------------------------------------------------//

        printf("%d\n",solucion);
        valores.clear();
    }


    return 0;
}
