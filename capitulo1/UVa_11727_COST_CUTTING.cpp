



#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    int TC;
    scanf ("%d", &TC); // número de casos while (TC--) { // repetir hasta llegar a O
    int c = 1;
while (c<=TC){//Repetir hasta llegar a 0
    int* salarios = new int[3];
    // vector<int> v(salarios,salarios+3); Uso de vector
    scanf ( "%d %d %d", &salarios[0], &salarios[1], &salarios[2]); // calcular respuesta al vuelo
    //sort(v.begin(),v.end()); uso de vector
    sort(salarios,salarios+3);
    printf("Case %d: %d\n",c++,salarios[1]);
    delete[] salarios;
}
    return 0;
}
