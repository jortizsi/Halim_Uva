#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// NOTA: LOS ARREGLOS USADOS AQUI SE ESTAN USANDO DESDE EL INDICE 1 PARA FACILITAR LOS CALCULOS


int main()
{




    bool primer_testcase = true;
    int k = 1;
    while(k>0){

            //lectura de numero de elementos del subconjunto S. Si k = 0, entonces no hay mas casos de prueba y se retorna 0.
            scanf("%d",&k);



            //__________________________________________________________________________________
            //Bloque para cumplir formato del juez
            //Imprimer una linea en blanco entre los output de los casos de prueba.
            if(primer_testcase){
                primer_testcase = false; // si es el primer testcase no imprimir linea en blanco
            }else if(k > 0){
                printf("\n"); //si falta computar un caso de prueba o mas, imprimir linea para separar la respuesta de la anterior
            }
            //__________________________________________________________________________________




            if(k>0){

                int* subconjunto_S = new int[k+1]; // declaracion de arreglo para el subconjunto
                for(int i = 1;i<=k;i++){   //lectura de valores del subconjuno
                        scanf ( "%lld", &subconjunto_S[i]);

                }
/*

                //_______________________________________________________________________-

                explicacion de la solucion



                1. PROBLEMA

                Se desean obtener las combinaciones de un conjunto S con k elementos (k>6)



                2. IDEA - LOGICA DE CADA ITERACION

                Primero con la lista de elementos ordenada se elige un elemento garantizando que queden
                al menos 5 elementos a su derecha. Esto para poder completar posteriormente
                la combinacion con 6 elementos en total y ordenada.

                Despues se elige un segundo elemento teniendo como primera opcion al elemento inmediatamente siguiente
                al que se escogio en el primer paso y  garantizando que queden al menos 4 elementos a su derecha.

                De la misma forma se eligen los demas elementos hasta haber elegido 6.




                3. ALGORITMO DE SOLUCION

                Los ciclos for aqui se usan para elegir en cada iteracion 6 elementos de izquierda a
                derecha de tal forma que es posible ir imprimiendo todas las combinaciones generadas segun varian
                los i de los ciclos.


                //_______________________________________________________________________-

                */

                    sort(subconjunto_S+1, subconjunto_S + k + 1); // ordenamiento del subconjunto

                    for(int i1 = 1; i1<=(k-5); i1++){
                    for(int i2 = i1+1; i2<=(k-4); i2++){
                    for(int i3 = i2+1; i3<=(k-3); i3++){
                    for(int i4 = i3+1; i4<=(k-2); i4++){
                    for(int i5 = i4+1; i5<=(k-1); i5++){
                    for(int i6 = i5+1; i6<=(k-0); i6++){

                     printf("%d ",subconjunto_S[i1]);
                     printf("%d ",subconjunto_S[i2]);
                     printf("%d ",subconjunto_S[i3]);
                     printf("%d ",subconjunto_S[i4]);
                     printf("%d ",subconjunto_S[i5]);
                     printf("%d\n",subconjunto_S[i6]);  //Impresion de una combinacion de 6 elementos del conjunto S

                }
                }
                }
                }

                }
                }





                delete[] subconjunto_S; //eliminacion del arreglo para redeclararlo en el siguiente testcase



            }

    }



    return 0;
}
