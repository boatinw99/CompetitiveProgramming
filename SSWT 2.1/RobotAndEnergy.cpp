#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int B= 100,MOD=1e9+7;
int base ;
int F[B][B];
int M[B][B];
int c[B][B];
int f[B];
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<base;i++)for(j=0;j<base;j++)for(k=0;k<base;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<base;i++)for(j=0;j<base;j++)
        a[i][j]=c[i][j],c[i][j]=0;
}
void pow(ll n)
{
    if(n==1)return ;
    pow(n/2);
    multi(F,F);
    if(n&1)multi(F,M);
}
bool chkpa(string s)
{
    int i;
    for(i=0;i<s.size();i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            return 0 ;
        }
    }
    return 1 ;
}
int cnt(string s)
{
    map<string,int> key ;
    int i,j,k ;
    for(i=0;i<s.size();i++)
    {
        for(j=1;i+j-1<s.size();j++)
        {
            if(chkpa(s.substr(i,j)))
            {
                key[s.substr(i,j)]++;
            }
        }
    }
    return key.size() ;
}
main()
{
    int n,m,i,j,x,y,T ;
    ll k ;
    string s;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >> s ;
            f[i*m+j]=cnt(s);
        }
    }
    base=n*m ;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&i,&j,&x,&y);
        F[x*m+y][i*m+j]++;
        F[i*m+j][x*m+y]++;
        M[x*m+y][i*m+j]++;
        M[i*m+j][x*m+y]++;
    }
    scanf("%lld",&k);
    for(i=0;i<base;i++)F[i][i]++,M[i][i]++;
    pow(k);
    int ans = 0,cnts=0 ;
    for(i=0;i<base;i++)
    {
        ans=0;
        for(j=0;j<base;j++)
        {
            ans=(ans+1ll*F[i][j]*f[j])%MOD;
        }
        printf("%d ",ans);
        cnts++;
        if(cnts==m)cnts=0,printf("\n");
    }
}
