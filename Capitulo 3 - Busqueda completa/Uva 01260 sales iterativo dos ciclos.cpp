#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
      long long t;
      long long n;
      scanf ("%lld", &t); // número de casos de prueba



      while (t--){//Repetir hasta llegar a 0

                long long sol_caso_i = 0;
                long long* lista_A = new long long[1000];
                scanf ("%lld", &n); //dias donde se registro informacion (largo de la lista A)

                for(long long i = 0;i<n;i++){
                    scanf ( "%lld", &lista_A[i]); //Lectura de valores de la lista A

                    for(long long j = 0;j<i;j++){   //Comparacion con los dias anteriores

                        if(lista_A[i] >= lista_A[j]){
                            sol_caso_i++;

                        }
                    }

                }


                printf("%lld\n",sol_caso_i);


                delete[] lista_A;
      }



        return 0;
}
