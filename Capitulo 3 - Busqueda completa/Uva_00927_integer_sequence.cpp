#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;



long long evaluar_polinomio(long long* polinomio, long long grado, long long x){

    long long s = 0;
    long long terminos = grado +1;
    for(long long i =0;i<terminos;i++){
        s = s + ( polinomio[i] * pow(x,i) );
    }
    return s;
}

long long solucion_positiva(double a, double b){
    if (a>0){
        return (long long) ceil(a);
    }else if(b>0){
        return (long long) ceil(b);
    }else{
        cout<<"No hay soluciones positivas";
        return -1;
    }
}


int main()
{
    long long c;
    long long i;
    long long d,k;


    scanf ("%lld", &c); // número de casos de prueba


while (c--){//Repetir hasta llegar a 0
             long long* coeficientes_polinomio = new long long[21];
             scanf ("%lld", &i); //grado del polinomio

             for(long long m = 0;m<=i;m++){   //coeficientes del polinomio
                scanf ( "%lld", &coeficientes_polinomio[m]);

             }

                 scanf ("%lld", &d); // n * d Repeticiones de cada valor en la secuencia
                 scanf ("%lld", &k); //termino deseado a imprimir





                //_____________________________-
                //SOLUCION
                double a = 1.0;
                double b = 1.0;
                double c = -( (2*k) / d);

                double sol_cuadratica_1 = ( -b + sqrt( (b*b) - (4*a*c)) )/ (2*a) ;
                double sol_cuadratica_2 = ( -b - sqrt( (b*b) - (4*a*c)) )/ (2*a) ;



               long long indice_en_b = solucion_positiva(sol_cuadratica_1,sol_cuadratica_2);


               long long solucion_final = evaluar_polinomio(coeficientes_polinomio, i, indice_en_b);

               if(c ==1){
                    printf("%lld",solucion_final);
               }else{
                    printf("%lld\n",solucion_final);
               }

                //_____________________________

                delete[] coeficientes_polinomio;



}

    return 0;
}
