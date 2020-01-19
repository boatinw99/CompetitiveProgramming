#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e6+9;
const int MOD=1e9+7;
int fi[N];
main()
{
    int i,j,q,Q,n,x,k;
    ///Pre-process
    fi[0]=0; fi[1]=1;
    for(i=2;i<N;i++)
    {
        fi[i]=(fi[i-1]+fi[i-2])%MOD;
    }
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d %d",&n,&q);
        int pr=fi[n];
        while(q--)
        {
            scanf("%d %d",&x,&k);
            pr=(1ll*fi[n-x+1]*k+pr)%MOD;
        }
        printf("%d\n",pr);
    }
}
