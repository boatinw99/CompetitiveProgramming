#include<bits/stdc++.h>
using namespace std ;
int dp[40][4];
main()
{
    int Q,a,b,c,h,n,i,j,x,a1,b1,c1,x1,a2,b2,c2,x2;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d %d %d %d %d",&a,&b,&c,&n,&h);
        dp[0][1]=a%h; dp[0][2]=b%h; dp[0][3]=c%h;
        for(i=1;(1<<i)<=n;i++)
        {
            x=dp[i-1][0]; a=dp[i-1][1]; b=dp[i-1][2]; c=dp[i-1][3];
            dp[i][0]=(2*x*c+2*a*b)%h;
            dp[i][1]=(4*x*b+2*a*c)%h;
            dp[i][2]=(6*a*x+2*b*c)%h;
            dp[i][3]=(6*x*x+3*a*a+2*b*b+c*c)%h;
        }
        i--;
        x1=dp[i][0]; a1=dp[i][1]; b1=dp[i][2]; c1=dp[i][3];
        n-=(1<<i);
        for(i--;n>0;i--)
        {
            if((1<<i)<=n)
            {
                x=x1; a=a1; b=b1; c=c1;
                x2=dp[i][0]; a2=dp[i][1]; b2=dp[i][2]; c2=dp[i][3];
                x1=(x*c2+x2*c+a*b2+a2*b)%h;
                a1=(2*x2*b+2*x*b2+a2*c+a*c2)%h;
                b1=(3*a2*x+3*a*x2+b2*c+b*c2)%h;
                c1=(6*x*x2+3*a*a2+2*b*b2+c*c2)%h;
                n-=(1<<i);
            }
        }
        printf("%d %d %d %d\n",x1,a1,b1,c1);
    }
}
