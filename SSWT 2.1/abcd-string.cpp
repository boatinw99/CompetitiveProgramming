#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MOD = 1e9+7,base=16 ;
char text[256];
int F[base][base],M[base][base],c[base][base];
int f[base];
int ch[4];
void multi(int a[base][base],int b[base][base])
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
    int Q,i,j,k,ans,x,y,c1,c2,c3 ;
    string s;
    ll n;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%lld %d",&n,&k);
        ans=0;
        memset(F,0,sizeof F);
        memset(M,0,sizeof M);
        for(i=0;i<base;i++)
        {
            x=i/4;
            for(j=0;j<base;j++)
            {
                y=j%4;
                if(x==y)
                {
                    F[i][j]=M[i][j]=1;
                }
            }
        }
        for(i=0;i<base;i++)f[i]=1;
        for(i=0;i<4;i++)ch[i]=1;
        while(k--)
        {
            cin >> s;
            if(s.size()==1)
            {
                ch[s[0]-'a']=0;
                c1=s[0]-'a';
                for(i=0;i<base;i++)
                {
                    x=i/4; y=i%4;
                    if(x==s[0]-'a'||y==s[0]-'a')f[i]=0;
                }
                for(i=0;i<base;i++)
                {
                    for(j=0;j<base;j++)
                    {
                        if(j/4==c1||j%4==c1||i/4==c1||i%4==c1)
                        {
                            F[i][j]=M[i][j]=0;
                        }
                    }
                }
            }
            else if(s.size()==2)
            {
                c1=s[0]-'a'; c2=s[1]-'a';
                f[c1*4+c2]=0;
                for(j=0;j<base;j++)
                {
                    F[c1*4+c2][j]=M[c1*4+c2][j]=0;
                }
            }
            else
            {
                c1=s[0]-'a'; c2=s[1]-'a' ; c3=s[2]-'a' ;
                F[c2*4+c3][c1*4+c2]=M[c2*4+c3][c1*4+c2]=0;
            }
        }
        if(n==1)
        {
            for(i=0;i<4;i++)ans+=ch[i];
        }
        else if(n==2)
        {
            for(i=0;i<base;i++)ans=(ans+f[i])%MOD;
        }
        else
        {
            pow(n-2);
            for(i=0;i<base;i++)for(j=0;j<base;j++)
                ans=(ans+1ll*F[i][j]*f[j])%MOD;
        }
        printf("%d\n",ans);
    }
}
