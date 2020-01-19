#include<bits/stdc++.h>
using namespace std ;
const int N=100009,K=10009;
vector<int> path[N];
vector<int> tech[K];
vector<int>::iterator it;
long long pr;
int town[N];
void dfs(int i)
{
    vector<int>::iterator itp;
    pr++;
    town[i]=2;
    for(itp=path[i].begin();itp!=path[i].end();itp++)
    {
        if(town[*itp]==2)
        {
            pr+=1e6;
            return ;
        }
        else if(town[*itp]==0)
        {
            dfs(*itp);
        }
    }
    town[i]=1;
}
main()
{
    int n,k,t,i,j,x,m,u ;
    scanf("%d %d %d",&n,&k,&t);
    for(i=1;i<=n;i++)
    {
        town[i]=0;
        scanf("%d %d",&x,&m);
        tech[x].push_back(i);
        while(m--)
        {
            scanf("%d",&u);
            path[i].push_back(u);
        }
    }
    pr=0;
    for(i=1;i<=k;i++)
    {
        for(it=tech[i].begin();it!=tech[i].end();it++)
        {
            if(!town[*it])
            {
                dfs(*it);
            }
        }
        if(pr>t)
        {
            break;
        }
    }
    i--;
    printf("%d",(i>0)?i:-1);
}
