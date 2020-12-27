#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{



    //_______________________

    int k = 1;



while(k>0){

    //numero de casas a revisar
    scanf("%d",&k);

    if(k>0){
        int a, b;
        int ai, bi;

        //Punto de division
        scanf ( "%d %d", &a, &b);


        for(int i =0;i<k; i++){
            //Punto de division
            scanf ( "%d %d", &ai, &bi);

            if(a == ai || b == bi){
                printf("divisa\n");
            }else if(ai>a && bi>b){
                printf("NE\n"); // DERECHA ARRIBA
            }else if(ai<a && bi<b){
                printf("SO\n"); // IZQUIERDA ABAJO
            }else if(ai>a && bi<b){
                printf("SE\n"); //DERECHA ABAJO
            }else if(ai<a && bi>b){
                printf("NO\n"); //IZQUIERDA ARRIBA
            }
        }
    }

}

    //_______________________

}






