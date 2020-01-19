#include<bits/stdc++.h>
using namespace std ;
const int N = 309;
int path[N][N];
vector<int> v ;
vector<int>::iterator it;
main()
{
    int n,i,j,T,u,k,x,y,z ;
    scanf("%d %d",&n,&T);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&path[i][j]);
        }
    }
    bool b=0;
    for(i=1;i<=n&&b==0;i++)
    {
        for(j=i+1;j<=n&&b==0;j++)
        {
            for(k=j+1;k<=n&&b==0;k++)
            {
                x=path[i][j]; y=path[i][k]; z=path[j][k];
                if(x+y!=z&&x+z!=y&&y+z!=x)
                {
                    x=i,y=j,z=k;
                    b++;
                }
            }
        }
    }
   // printf("%d %d %d\n",x,y,z);
    int par=0;
    for(i=1;i<=n;i++)
    {
        if(i!=x&&i!=y&&i!=z&&path[x][i]+path[i][y]==path[x][y]
           &&path[x][i]+path[i][z]==path[x][z]&&
           path[y][i]+path[i][z]==path[y][z])
        {
            par=i;
            break;
        }
    }
    v.push_back(x); v.push_back(y); v.push_back(z);
    if(T==1)
    {
        printf("%d",par);
        return 0 ;
    }
    printf("%d",par);
    for(i=1;i<=n;i++)
    {
        b=0;
        for(it=v.begin();it!=v.end();it++)
        {
            if(i==*it||i==par||path[i][*it]!=path[i][par]+path[par][*it])
            {
                b++;
                break;
            }
        }
        if(b==0)
        {
            v.push_back(i);
        }
    }
    printf("\n%d",v.size());
}
