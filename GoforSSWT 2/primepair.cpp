#include<stdio.h>
const int N = 1e6+9 ;
const int M = 1e6 ;
int prime[N];
int dis[N];
main()
{
    int A,B,C,D,i,j ;
    for(i=2;i<=M/2;i++)
    {
        prime[i]=i;
    }
    for(i=2;i<=M/2;i++)
    {
        if(prime[i]==i)
        {
            dis[i]++;
            for(j=2;j*i<=M/2;j++)
            {
                while(prime[j*i]%i==0)
                {
                    dis[j*i]++;
                    prime[j*i]/=i;
                }
            }
        }
    }
    while(scanf("%d%d%d%d",&A,&B,&C,&D)==4)
    {
    int MAX = 0 ;
    int sum = 0 ;
    int x=0,y=0,l,r ;
    for(i=2;i<=B;i++)
    {
        if(dis[i]>=MAX)
        {
            l=B/i*i; r=D/i*i;
            if(l>=A&&r>=C)
            {
                if(dis[i]>MAX)
                {
                    MAX=dis[i];
                    sum=l+r;
                    x=l ; y=r;
                }
                else
                {
                    if(l+r>sum)
                    {
                        sum=l+r ;
                        x=l ; y=r ;
                    }
                    else if(l+r==sum&&l>x)
                    {
                        x=l; y=r ;
                    }
                }
            }
        }
    }
        if(x==0)x=B,y=D;
        printf("%d %d\n",x,y);
    }
    return 0;
}
