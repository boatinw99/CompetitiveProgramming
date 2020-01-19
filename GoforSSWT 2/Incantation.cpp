#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = (1<<7)+9 ;
stack<int> st;
int str[N];
ll dp[30][N][N];
ll dpans[40][N][N];
int cross[N][N];
int part[N][N];
ll pre[30][N][N];
main()
{
    int n,k,i,j,bits,x,y,d,all,now,p=1,q=1,d1,d2 ;
    ll pr=0,t;
    scanf("%d %d",&n,&k);
    bits=1<<k;
    for(i=0;i<bits;i++)scanf("%d",&str[i]);
    /*ok*/
    for(i=0;i<bits;i++)
    {
        d=i;
        for(j=k-1;j>0;j--)
        {
            if(((1<<j)&d)!=0)
            {
                d-=(1<<j);
            }
            part[i][j]=d;
        }
    }
    /*ok*/
    for(i=0;i<bits;i++)
    {
        for(j=0;j<bits;j++)
        {
            y=j; y>>=1;
            for(d=1;d<k;d++)
            {
                x=part[i][d];
                all=(x*(1<<(k-d)))+y;
                cross[i][j]+=str[all];
                y>>=1;
            }
        }
    }
    /*ok*/
    now=k*2;
    p=2;
    for(i=0;i<bits;i++)
    {
        dp[1][i][i]=str[i];
        for(j=0;j<bits;j++)
        {
            pre[1][i][j]=cross[i][j]+str[j];
        }
    }
    ///process
    for(;now<=n;now*=2,p++)
    {
        for(i=0;i<bits;i++)
        {
            for(j=0;j<bits;j++)
            {
                for(d=0;d<bits;d++)
                {
                    if(dp[p-1][i][j]>0)
                    dp[p][i][d]=max(dp[p][i][d],
                            dp[p-1][i][j]+pre[p-1][j][d]);
                }
            }
        }
        for(i=0;i<bits;i++)
        {
            for(j=0;j<bits;j++)
            {
                for(d=0;d<bits;d++)
                {
                    pre[p][i][d]=max(pre[p][i][d],cross[i][j]+dp[p][j][d]);
                }
            }
        }
    }
    now/=2;
    p--;
    n-=now;
    for(i=0;i<bits;i++)
    {
        for(j=0;j<bits;j++)
        {
            dpans[0][i][j]=dp[p][i][j];
        }
    }
    q=1;
    /**/
    for(now/=2,p--;n>=k;now/=2,p--)
    {
        if(n<now)continue;
        n-=now;
        for(i=0;i<bits;i++)
        {
            for(j=0;j<bits;j++)
            {
                for(d=0;d<bits;d++)
                    if(dpans[q-1][i][j]>0)
                        dpans[q][i][d]=max(dpans[q][i][d],
                            dpans[q-1][i][j]+pre[p][j][d]);
            }
        }
        q++;
    }
    /**/
    q--;
    for(j=0;j<bits;j++)
    {
        t=0;
        for(i=0;i<bits;i++)
        {
            t=max(t,dpans[q][i][j]);
        }
        for(i=0;i<(1<<n);i++)
        {
            d1=j;
            y=k-1;
            if((d1&(1<<y))>0)d1-=(1<<y);
            d2=i;
            for(d=1;d<=n;d++)
            {
                st.push(d2%2);
                d2/=2;
            }
            x=0;
            for(d=1;d<=n;d++)
            {
                d2*=2;
                d2+=st.top();
                st.pop();
                x+=str[d1*(1<<d)+d2];
                y--;
                if((d1&(1<<y))>0)d1-=(1<<y);
            }
            pr=max(pr,t+x);
        }
    }
    printf("%lld",pr);
}
