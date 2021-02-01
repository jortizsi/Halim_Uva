


#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

vector<long long> * adjList;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long n,m;
    while(scanf("%lld %lld",&n,&m) != EOF){
    long long * a = new long long[n+1];
    long long maximum = -1;
    for(long long i = 1; i<=n; i++){
        scanf("%lld",&a[i]);
        if(maximum < a[i]){
            maximum = a[i];
        }
    }
    //tengo el maximo y el arreglo
    adjList = new vector<long long> [maximum+1];
    for(long long i = 1; i<=n;i++){
        adjList[a[i]].push_back(i);
    }
    for(int i = 0; i<m;i++){
        long long k;
        long long v;
        scanf("%lld %lld",&k,&v);
        if((long long)adjList[v].size()<k){
            printf("0\n");
        }else{
            printf("%lld\n",adjList[v][k-1]);
        }
    }
    delete[]a;
    delete[]adjList;
    }
    return 0;
}
