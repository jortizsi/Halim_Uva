#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int ocurrencia_letra(string cadena, char c){
    return count(cadena.begin(),cadena.end(),c);
}


int main()
{


    int testcases;
    scanf("%d",&testcases);
    for(int t = 0; t<testcases; t++){


            string cadena_a;
            string cadena_b;


            cin>> cadena_a;
            cin>>cadena_b;


            int ocurrencias[123];
            for(char i = 97;i<=122; i++){
                ocurrencias[(int)i] = ocurrencia_letra(cadena_b, i);
                //cout<<"ocurrencias "<<i<<" = "<<ocurrencias[(int)i]<<"\n";
            }

            int respuesta = 0;
            int l = cadena_a.size();
            //cout<<"largo cadena a = "<<l<<"\n";

            int i = 0;
            bool continuar = true;
            while(i<l && continuar){

                char letra = cadena_a.at(i);
                //cout<<"buscando "<<letra<<"\n";

                if(ocurrencias[(int)letra] > 0){
                    ocurrencias[(int)letra] = ocurrencias[(int)letra] - 1;
                    respuesta++;
                }else{
                    continuar = false;
                }

                i++;

            }

            printf("%d\n",respuesta);

    }

    return 0;
}
