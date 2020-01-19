#include<bits/stdc++.h>
using namespace std ;
deque<pair<int,int> > dq; /// value , pos
const int N = 6009;
int dp[N][N];
int a[N];
main()
{
    int n,m,i,j,x,y ;
    scanf("%d %d",&n,&m);
    m++;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    int l=0,r=n;
    bool b=0;
    while(l+1<r)
    {
        int mid=l+r>>1;
        for(j=1;j<=2*n-1;j++)dp[1][j]=1;
        for(i=2;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                x=j;
                while(!dq.empty()&&j-dq.front().second>mid)
                {
                    dq.pop_front();
                }
                if(!dq.empty()&&dq.front().first<a[x])
                {
                    dp[i][x]=1;
                }
                if(dp[i-1][x]==1)
                {
                    dp[i-1][x]=0;
                    while(!dq.empty()&&dq.back().first>a[x])
                    {
                        dq.pop_back();
                    }
                    dq.push_back({a[x],j});
                }
            }
            for(j=n+1;j<=n+mid;j++)
            {
                x=j-n;
                while(!dq.empty()&&j-dq.front().second>mid)
                    dq.pop_front();
                if(!dq.empty()&&dq.front().first<a[x])
                {
                    dp[i][x]=1;
                }
            }
            while(!dq.empty())dq.pop_back();
        }
        b=0;
        for(j=1;j<=n;j++)
        {
            if(dp[m][j]==1)
            {
                b++;
            }
            dp[m][j]=0;
        }
        if(b==0)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    printf("%d",r);
}
