#include<bits/stdc++.h>
using namespace std ;
const int B= 1<<4 ,md = 1e9+7;
int F[B][B];
int M[B][B];
int c[B][B];
int p[B];
int cnt[B];
int b;
int mask ;
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<mask;i++)for(j=0;j<mask;j++)for(k=0;k<mask;k++)
        c[i][j]=(c[i][j]+a[i][k]*1ll*b[k][j])%md;
    for(i=0;i<mask;i++)for(j=0;j<mask;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void pow(int n)
{
    if(n==1)return ;
    pow(n>>1);
    multi(F,F);
    if(n&1)multi(F,M);
}
void primefactor(int m,int D)
{
    int i,j,k,pos=0 ;
    b=0 ;
    for(i=2;i<=D;i++)
    {
        if(D%i==0)
        {
            b++;
            p[pos]=1;
            while(D%i==0)D/=i,p[pos]*=i;
            pos++;
        }
    }
    mask=1<<b;
    memset(cnt,0,sizeof cnt);
    memset(F,0,sizeof F);
    for(i=1;i<=m;i++)
    {
        int bits = 0 ;
        for(j=0;j<b;j++)if(i%p[j]==0)bits+=1<<j;
        cnt[bits]++;
    }
    for(i=0;i<mask;i++)for(j=0;j<mask;j++)for(k=0;k<mask;k++)
        if((j|k)==i)F[i][j]+=cnt[k];
    for(i=0;i<mask;i++)for(j=0;j<mask;j++)M[i][j]=F[i][j];
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T,n,m,l,r,i,j ;
    cin >> T ;
    while(T--)
    {
        cin >> n >> m >> l >> r ;
        /// prime factor of m
        int ans=0;
        for(l;l<=r;l++)
        {
            ///store F[i][j],M[i][j];
            primefactor(m,l);
            pow(n);
            ans=(ans+F[mask-1][0])%md;
        }
        cout << ans << '\n';
    }
}
