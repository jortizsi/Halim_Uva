



#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

long long DP[100001]; //TABLA RECORDATORIA DE DP

//Relacion de Recurrencia o backtracking recursivo sin memorizacion
long long cost(long long* h, long long i){
    if(i == 0 || i == 1){
        return 0;
    }else if(i == 2){
        return abs(h[i]-h[i-1]);
    }else{
        return min(abs(h[i]-h[i-1])+cost(h,i-1),abs(h[i]-h[i-2])+cost(h,i-2));
    }
}

//Resolviendo el problema ahora usando programacion dinamica de abajo hacia arriba o en ingles bottom up
long long memoizedCostBottomUpDP(long long* h, long long i){
    for(int q = 0; q<=i ;q++){
        if(q == 0 || q == 1){
            DP[q] = 0;
        }else if(q == 2){
            DP[q] = abs(h[q]-h[q-1]);
        }else{
            DP[q] = min(abs(h[q]-h[q-1])+DP[q-1],abs(h[q]-h[q-2])+DP[q-2]);
        }
    }
    return DP[i];
}

int main(){
    long long n;
    scanf("%lld",&n);
    long long* h = new long long[n+1];
    h[0] = 0;
    for(long long i = 1; i<=n ;i++){
        scanf("%lld",&h[i]);
    }
    //printf("%lld",cost(h,n));
    printf("%lld",memoizedCostBottomUpDP(h,n));
    delete[] h;
    return 0;
}
