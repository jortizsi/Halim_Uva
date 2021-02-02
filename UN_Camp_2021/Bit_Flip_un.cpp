#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    bool xb;
    bool yb;

    int x;
    int y;
    int t;
    int bits_distintos;


    scanf("%d",&t);
    for (int i = 0; i<t; i++){


            scanf("%d",&x);
            y = x-1;
            bits_distintos = 0;

            for (int k = 31; k >= 0; k--) {
                xb = (bool)(x&(1<<k));
                yb = (bool)(y&(1<<k));
                //cout<<xb<<"  "<<yb<<"\n";
                if(xb^yb){bits_distintos++;}
            }

            printf("%d\n",bits_distintos);

    }


    return 0;
}
