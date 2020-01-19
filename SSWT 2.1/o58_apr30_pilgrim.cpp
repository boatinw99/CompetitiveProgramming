#include<bits/stdc++.h>
using namespace std ;
const int N = 209 ,md= 1e9+9 ;
int F[N][N],M[N][N],c[N][N],B ;
void multi(int a[N][N],int b[N][N])
{
    for(int i=1;i<=B;i++)for(int j=1;j<=B;j++)for(int k=1;k<=B;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%md ;
    for(int i=1;i<=B;i++)for(int j=1;j<=B;j++)a[i][j]=c[i][j],c[i][j]=0 ;
}
void pow(int n)
{
    if(n==1)return ;
    pow(n>>1);
    multi(F,F);
    if(n&1)multi(F,M);
}
main()
{
    int n,m,k,i,j,u,v,x ;
    cin >> n >> m >> k ;
    B=n ;
    while(m--)
    {
        cin >> u >> v >> x ;
        if(x==1)
        {
            F[u][v]++;
            F[v][u]++;
        }
        else
        {
            int tmp = u ,tmp1=x;
            while(x>1)
            {
                x--;
                F[tmp][B+1]++;
                B++;
                tmp=B;
            }
            F[tmp][v]++;
            x=tmp1 ;
            tmp=v ;
            while(x>1)
            {
                x--;
                F[tmp][B+1]++;
                B++;
                tmp=B;
            }
            F[tmp][u]++;
        }
    }
    for(i=1;i<=B;i++)for(j=1;j<=B;j++)M[i][j]=F[i][j];
    if(k==0)
    {
        cout << "1" << '\n' ;
        for(i=2;i<=n;i++)cout << "0" << '\n' ;
        return 0 ;
    }
    pow(k);
    for(i=1;i<=n;i++)
    {
        cout << F[i][1] << '\n' ;
    }
}
