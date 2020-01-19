#include<bits/stdc++.h>
using namespace std ;
const int MOD = 1e9+7 , B = 1<< 6 ;
int F[B][B];
int M[B][B];
int c[B][B];
int f[B];
int base ;
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<base;i++)for(j=0;j<base;j++)for(k=0;k<base;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%MOD;
    for(i=0;i<base;i++)for(j=0;j<base;j++)
        a[i][j]=c[i][j],c[i][j]=0;
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
    int Q,i,j,k,x,y,n,LOG,val  ;
    scanf("%d",&Q);
    for(i=0;i<B;i++)
    {
        f[i]=1;
        x=i ;
        for(j=5;j>=0;j--)
        {
            y=(1<<j);
            if((y&x)>0&&((y/2)&x)>0)
            {
                j--;
            }
            else if((y&x)>0)
            {
                f[i]=0;
                break;
            }
        }
    }
    while(Q--)
    {
        scanf("%d %d",&base,&n);
        if(n==1)
        {
            printf("%d\n",base);
            continue ;
        }
        base =1<<base;
        for(j=0;j<B;j++)F[0][j]=M[0][j]=1;
        for(i=1;i<base;i++)
        {
            LOG=log2(i);
            LOG = 1<< LOG ;
            x=LOG&i;
            for(j=0;j<base;j++)
            {
                y=LOG&j ;
                if(y>0&&((LOG/2)&i)==0)
                {
                    /// 10xx
                    /// 1xxx
                    F[i][j]=M[i][j]=0;
                }
                else if(y>0)
                {
                    ///11xx -> i
                    ///1xxx -> j
                    F[i][j]=M[i][j]=F[i-LOG-LOG/2][j-LOG];
                }
                else if((LOG/2&i)==0)
                {
                    ///10xx
                    ///0xxx
                    F[i][j]=M[i][j]=F[i-LOG][j];
                }
                else
                {
                    ///11xx
                    ///0xxx
                    F[i][j]=M[i][j]=F[i-LOG][j]+
                                F[i-LOG-LOG/2][j-(LOG/2&j)];
                }
            }
        }
        pow(n-1);
        int ans=0 ;
        for(i=0;i<base;i++)
        {
            for(j=0;j<base;j++)
            {
                ans=(ans+F[i][j]*f[j])%MOD;
            }
        }
        printf("%d\n",ans);
    }
}
