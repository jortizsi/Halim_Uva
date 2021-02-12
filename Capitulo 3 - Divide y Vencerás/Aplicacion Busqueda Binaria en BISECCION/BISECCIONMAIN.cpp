#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

long double epsilon = 1E-9;

//     inicializacion   condicion parada  actualizacion
/*for(   int i = 0;     i<n;               i++){

}
*/

/*double ourSqrt(double a, double xi, double xn){
    if(abs(xi-xn)<= epsilon && abs(((xi*xi)-a)-((xn*xn)-a)) <= epsilon){
        double newX = ((xi+xn)/2);
        return newX;
    }else{
        double newX = ((xi+xn)/2);
        if(((newX*newX)-a)<0){
            return ourSqrt(a,newX,xn);
        }else if (((newX*newX)-a)>0){
            return ourSqrt(a,xi,newX);
        }
    }
}*/

long double ourSqrt(long double a,long double xi,long double xn){
    long double newX = ((xi+xn)/2);
    while(!(abs(xi-xn)<= epsilon && abs(((xi*xi)-a)-((xn*xn)-a)) <= epsilon)){
        newX = ((xi+xn)/2);
        if(((newX*newX)-a)<0){
            xi = newX;
        }else if (((newX*newX)-a)>0){
            xn = newX;
        }
    }
    return ((xi+xn)/2);
}

int main(){
    cout<<"input the number in order to get its square root:"<<endl;
    long double a;
    cin>>a;
    cout<<setprecision(9)<<ourSqrt(a,0,a)<<endl;
    return 0;
}
