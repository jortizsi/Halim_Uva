



#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

string getMaker(int P,int D,string * M,int * L,int * H){
    int index = -1;
    int counter = 0;
    for(int i = 0; i<D;i++){
        if(L[i]<=P && P<=H[i]){
            index = i;
            counter++;
        }
    }
    if(counter > 1 || counter == 0){
        return "UNDETERMINED";
    }else if(counter == 1){
        return M[index];
    }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int D,Q;
        scanf("%d",&D);
        string* M = new string[D];
        int* L = new int[D];
        int* H = new int[D];
        for(int i = 0; i<D;i++){
            cin>>M[i];
            cin>>L[i];
            cin>>H[i];
        }
        scanf("%d",&Q);
        for(int i = 0; i<Q;i++){
            int P;
            scanf("%d",&P);
            string str_obj(getMaker(P,D,M,L,H));
            char* char_arr = &str_obj[0];
            puts(char_arr);
        }
        if(T){
            puts("");
        }
        delete[]M;
        delete[]L;
        delete[]H;
    }
    return 0;
}
