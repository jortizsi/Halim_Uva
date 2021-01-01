#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//Funcion para obtener las coordenadas fila/columna con x,y entre [0,4]
//correspondientes a un sector dado entre [0,24]
int* get_coordenadas(int codigo_sector){

    int* xy = new int[2];

    xy[0] = codigo_sector%5;
    xy[1] = (int)(codigo_sector/5);

    return xy;
}



int main()
{


int distritos_en_mapa;

int t;
scanf("%d",&t); //lectura numero de casos de prueba



 while(t--){ //iterar t casos de prueba


                //DECLARACIONES DE VARIABLES Y ARREGLOS UTILES

                int suma_minima = 100000000; // minimo inicial tiende a infinito
                int* ubicaciones_optimas = new int[5]; //arreglo para guardar codigos de casillas o distritos optimos
                int habitantes[25] = {0}; //todas las casillas que explicitamente no se les asigna poblacion, no tienen.
                int memorizacion_distancias[25][25]; //arreglo tipo DP para mejorar velocidad de ejecucion.






                //LECTURA DATOS DE DISTRITOS DE LA CIUDAD

                scanf ( "%d", &distritos_en_mapa); //numero de casillas con habitantes. Por cada una se leen 3 datos.
                for(int i = 0;i<distritos_en_mapa;i++){   //Lectura de datos de cada distrito. coordenadas tipo matriz.
                        int x,y,poblacion;
                        scanf ( "%d %d %d" , &x, &y, &poblacion);
                        habitantes[(x*5 + y)] = poblacion; //se guarda en un arreglo por codigo, no coordenadas, la poblacion.
                }




              //PREPROCESAMIENTO DE DISTANCIAS ENTRE DISTRITOS Y UBICACIONES POSIBLES DE OFICINAS

              for(int sector = 0; sector<25; sector++){
                    int* xy_sector = get_coordenadas(sector); //se pasa el cogigo del distrito a coordenadas
                        for(int oficina = 0; oficina<25; oficina++){
                                int* xy_oficina = get_coordenadas(oficina); //se pasa el cogigo del distrito a coordenadas
                                memorizacion_distancias[sector][oficina] = //calculo de poblacion multiplicado distancia manhattan
                                    habitantes[sector]*( abs(xy_oficina[0] - xy_sector[0]) + abs(xy_oficina[1] - xy_sector[1]) );
                        }
                }


//_______________________________________________________________

            //SOLUCION POR BUSQUEDA COMPLETA

             int* direcciones_oficinas = new int[5]; //array para codigos de distritos candidatos a ubicar oficinas en cada iteracion.


                    int k = 25;
                    for(int i1 = 1; i1<=(k-4); i1++){
                    for(int i2 = i1+1; i2<=(k-3); i2++){
                    for(int i3 = i2+1; i3<=(k-2); i3++){    //Generador de combinaciones 25C5 para los valores de 1 a 25
                    for(int i4 = i3+1; i4<=(k-1); i4++){    //como este ejercicio usa indices de 0 a 24. debe posteriormente restarse 1.
                    for(int i5 = i4+1; i5<=(k-0); i5++){    //Nota: Este generador se explica en "Uva_00441_Lotto_iterativo_6_ciclos" en este mismo GitHub.

                        direcciones_oficinas[0]= i1-1;
                        direcciones_oficinas[1]= i2-1;
                        direcciones_oficinas[2]= i3-1;      //combinacion actual de la iteracion. Se ajusta de 1...25 a 0...24
                        direcciones_oficinas[3]= i4-1;
                        direcciones_oficinas[4]= i5-1;



                        int valor_optimo_distancias = 0;         //Se determina que oficina esta mas proxima a cada distrito
                                                                 //y a partir de alli se halla la suma minima para la asignacion actual
                        for(int sector = 0; sector<25; sector++){
                                int distacia_oficina_mas_cercana = 100000;
                                for(int oficina_i = 0; oficina_i<5; oficina_i++){

                                        distacia_oficina_mas_cercana =
                                          min(memorizacion_distancias[sector][direcciones_oficinas[oficina_i]], distacia_oficina_mas_cercana);

                                }

                                valor_optimo_distancias = valor_optimo_distancias + distacia_oficina_mas_cercana;

                        }


                        //Si la suma optima de la combinacion actual es la mejor hasta el momento
                        //guardar las ubicaciones de las 5 oficinas por codigo de sector junto al valor
                        //de la suma minima para comparaciones futuras.
                        if(valor_optimo_distancias < suma_minima){
                            for(int i = 0; i<5;i++){
                                ubicaciones_optimas[i] = direcciones_oficinas[i];
                            }
                                suma_minima = valor_optimo_distancias;
                        }



                }
                }
                }
                }
                }
//_______________________________________________________________






                    //Imprimir solucion del caso de prueba enesimo
                     printf("%d ",ubicaciones_optimas[0]);
                     printf("%d ",ubicaciones_optimas[1]);
                     printf("%d ",ubicaciones_optimas[2]);
                     printf("%d ",ubicaciones_optimas[3]);
                     printf("%d\n",ubicaciones_optimas[4]);

                     delete[] ubicaciones_optimas; //borrar arreglo de solucion para redeclararlo en el siguiente testscase

 }



}
