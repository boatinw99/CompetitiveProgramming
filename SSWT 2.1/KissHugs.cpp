#include<bits/stdc++.h>
using namespace std ;
const int B = 5 ,MOD = 1000000007 ;
int f[B]={1,1,1,1,0};
int F[B][B];
int M[B][B]={{1,0,0,0,0},{0,0,1,0,1},{1,1,0,0,0},{0,0,1,0,1},{0,0,0,1,0}};
int c[B][B];
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<B;i++)for(j=0;j<B;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void pow(int n)
{
    if(n==1)return ;
    pow(n/2);
    multi(F,F);
    if(n&1)multi(F,M);
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T,n,i,j ;
    cin >> T ;
    while(T--)
    {
        cin >> n;
        for(i=0;i<B;i++)for(j=0;j<B;j++)F[i][j]=M[i][j];
        if(n==1)cout << 2 ;
        else if(n==2)cout << 4 ;
        else
        {
            int ans=0 ;
            pow(n-2);
            for(i=0;i<B;i++)for(j=0;j<B;j++)
                ans=(ans+F[i][j]*f[j])%MOD;
            cout << ans ;
        }
        cout << '\n';
    }
}
