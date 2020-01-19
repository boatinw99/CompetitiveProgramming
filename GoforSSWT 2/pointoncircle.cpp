#include<bits/stdc++.h>
using namespace std ;
const int N = 1009;
int dist[N][N];
int ans[N];
main()
{
    int n,k,i,j,x,y,max1=0,c1,c2;
    scanf("%d %d",&n,&k);
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            scanf("%d",&dist[i][j]);
        }
    }
    ans[1]=0;
    for(j=2;j<=k;j++)
    {
        x=dist[1][j];
        y=n-dist[1][j];
        for(i=2;i<j;i++)
        {
            if(dist[i][j]!=min(abs(x-ans[i]),abs(n-ans[i]+x))
               ||ans[i]==x)
            {
                x=-1;
                break;
            }
        }
        if(x!=-1)ans[j]=x;
        else ans[j]=y;
    }
    for(i=1;i<=k;i++)
    {
        printf("%d\n",ans[i]);
    }
}
