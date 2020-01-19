#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MOD = 1e9+7 ,B=51 ;
int F[B][B],M[B][B],c[B][B];
int f[B];
int base;
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
main()
{
    ll n;
    int Q,ans1,ans2,i,j,k,d ;
    scanf("%d",&Q);
    f[0]=1; f[1]=1; M[0][0]=1;
    for(d=1;d<=Q;d++)
    {
        scanf("%lld%d",&n,&k);
        printf("Case #%d: ",d);
        if(n==1)///base case
        {
            if(k==0||k==1)printf("1");
            else printf("0");
            printf("\n");
            continue;
        }
        k++;
        base=k;
        memset(F,0,sizeof F);
        F[0][0]=1;
        for(i=1;i<k;i++)
        {
            F[0][i]=M[0][i]=1;
            F[i][i-1]=M[i][i-1]=1;
        }
        pow(n-1);
        ans1=0;
        for(i=0;i<k;i++)
        {
            ans1=(ans1+F[i][0])%MOD;
            ans1=(ans1+F[i][1])%MOD;
        }
        ans2=0;
        k--;
        base=k;
        memset(F,0,sizeof F);
        F[0][0]=1;
        for(i=1;i<k;i++)
        {
            F[0][i]=M[0][i]=1;
            F[i][i-1]=M[i][i-1]=1;
        }
        pow(n-1);
        for(i=0;i<k;i++)
        {
            ans2=(ans2+F[i][0])%MOD;
            ans2=(ans2+F[i][1])%MOD;
        }
        ans1=(ans1-ans2+MOD)%MOD;
        printf("%d\n",ans1);
    }
}
