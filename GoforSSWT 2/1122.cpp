#include<bits/stdc++.h>
using namespace std ;
const int N = 1009;
vector<pair<int,int> > path ;
vector<pair<int,int> > ::iterator it,it1 ;
bool b[N][N];
int comp[2];
main()
{
    int n,m,ans1=0,ans2=0,u,v,i ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d",&u,&v);
        b[u][v]++;
        b[v][u]++;
        path.push_back({u,v});
    }
    for(it=path.begin();it!=path.end();it++)
    {
        comp[0]=it->first; comp[1]=it->second;
        for(it1=it+1;it1!=path.end();it1++)
        {
            u=it1->first; v=it1->second;
            if(u!=comp[0]&&v!=comp[0]&&u!=comp[1]&&v!=comp[1])
            {
                int co=2;
                for(i=0;i<=1;i++)
                {
                    if(b[comp[i]][u]==1)co++;
                    if(b[comp[i]][v]==1)co++;
                }
                if(co==5)ans1++;
                else if(co==6)ans2++;
            }
        }
    }
    printf("%d",ans1/2+ans2/3);
}
