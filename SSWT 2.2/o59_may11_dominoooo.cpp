#include<bits/stdc++.h>
using namespace std ;
const int B = 1<<7,md=1e9+7 ;
int F[B][B],M[B][B],c[B][B],f[B];
int base;
void multi(int a[B][B],int b[B][B])
{
    for(int i=0;i<base;i++)for(int j=0;j<base;j++)for(int k=0;k<base;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%md ;
    for(int i=0;i<base;i++)for(int j=0;j<base;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void pow(int n)
{
    if(n==1)return ;
    pow(n>>1);
    multi(F,F);
    if(n&1)multi(F,M);
}
int chk(int x)
{
    for(int i=base>>1;i>0;)
    {
        if((x&i)&&(x&i/2))i>>=2;
        else if(x&i)return 0 ;
        else i>>=1;
    }
    return 1 ;
}
void trans(int x,int y)
{
    for(int i=0;i<base;i++)
    {
        if((x&i)==0&&(i&y)==i)
        {
            F[x][y]+=chk(i^y);
        }
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j ;
    cin >> n >> m ;
    base=1<<n ;
    for(i=0;i<base;i++)f[i]=chk(i);
    for(i=0;i<base;i++)for(j=0;j<base;j++)trans(i,j);
    for(i=0;i<base;i++)for(j=0;j<base;j++)M[i][j]=F[i][j];
    pow(m-1);
    int ans = 0 ;
    for(i=0;i<base;i++)for(j=0;j<base;j++)ans=(ans+1ll*F[i][j]*f[i])%md ;
    cout << ans ;
}
