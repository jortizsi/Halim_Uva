#include <iostream>
#include <bits/stdc++.h>

using namespace std;


//_____________________________________________________
//Adaptado de https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/



//Version eficiente en memoria para valores Positivos
int maxSubArraySumOptimizado(vector<int> a, int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}





//Version dp con memorizacion  para valores POSITIVOS
int Kadane_maxSubArraySum_positivos(vector<int> a, int size)
{
    int DP_memorization[size] = {0}; //arreglo DP para maximo intervalo
    int max_so_far = INT_MIN;        //usando elementos del 0 al i
    int max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {

        //el primer elemento es el primer candidato
        //a ser intervalo maximo.
        //si es negativo o 0 no se toma
        //de modo que el maximo seria 0
        //es decir intervalo de 0 elementos.
        if( i==0 && (a[i]>0) ){max_ending_here = a[i];}
        else if(i==0){max_ending_here = 0;}


        //para cada elemento i se vera si este elemento puede
        //continuar el intervalo anterior o si anula el acumulado
        //y se debe considerar un nuevo intervalo
        else{ max_ending_here = DP_memorization[i-1] + a[i]; }

        //si el acumulado actual supera al maximo actual,
        //actualizar el maximo actual
        if (max_so_far < max_ending_here){
            max_so_far = max_ending_here;
        }

        //si el acumulado actual es negativo
        //no considerar sus elementos
        //y pasar a uno nuevo
        if (max_ending_here < 0){
            max_ending_here = 0;
        }

        DP_memorization[i] = max_ending_here;

    }
    return max_so_far;
}




//version para valores irrstrictos en signo
int Kadane_maxSubArraySum(vector<int> a, int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];

   //para cada elemento i
   //la decision consiste en si tomarlo
   //como parte de un intervalo existente
   //o de uno nuevo.

   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
//_____________________________________________________



int main()
{
    int n;
    int leido;
    int solucion;

    vector<int> numeros;

    scanf("%d",&n);
    while(n > 0){

            for(int i = 0; i<n; i++){
                scanf("%d",&leido);
                numeros.push_back(leido);
            }

            solucion = Kadane_maxSubArraySum(numeros,n);
            if(solucion > 0){printf("The maximum winning streak is %d.\n",solucion);}
            else{printf("Losing streak.\n");}


            numeros.clear();
            scanf("%d",&n);

    }

    return 0;
}
