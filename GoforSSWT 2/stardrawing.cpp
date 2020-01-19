#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
vector<int>path[N];
set<vector<int> > noncycle3;
set<pair<int,int> > cycle3;
vector<int> s;
vector<int>::iterator it1;
int deg[N];
int cycle[N],noncycle[N];
bool visited[N];
pair<int,bool> dfs(int u,int v)
{
    vector<int>::iterator it ;
    pair<int,bool> pib;
    pib={0,0};
    visited[u]++;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(*it!=v&&visited[*it]==1)
        {
            //printf("%d->%d\n",u,*it);
            return {1,1};
        }
        else if(*it!=v)
        {
            pib=dfs(*it,u);
        }
    }
    pib.first++;
    return pib ;
}
int dfs1(int u)
{
    vector<int>::iterator it ;
    int k=1;
    visited[u]++;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(visited[*it]==0)
        {
            k+=dfs1(*it);
        }
    }
    return k ;
}
main()
{
    vector<int>::iterator it ;
    int n,m,i,j,u,v,d[3],q=0 ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        path[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int x;
    pair<int,bool> pib;
    bool cy;
    int a,b,c;
    for(i=1;i<=n;i++)
    {
        if(deg[i]==3)
        {
            cy=0;
            s.clear();
            visited[i]++;
            for(it=path[i].begin();it!=path[i].end();it++)
            {
                if(visited[*it]==1)cy=1;
                else
                {
                    pib=dfs(*it,i);
                    if(pib.second==0)
                    {
                        s.push_back(pib.first);
                    }
                    else
                    {
                        a=pib.first;
                    }
                }
            }
            if(cy==0)
            {
                sort(s.begin(),s.end());
                noncycle3.insert(s);
            }
            else cycle3.insert({a,*s.begin()});
           /// type.insert({3,s});
        }
    }
    //printf("%d",noncycle3.size());
    int ans=0;
    for(i=1;i<=n;i++)
    {
        if(deg[i]==1&&visited[i]==0)
        {
            x=dfs1(i);
            //printf("%d %d",pib.first,pib.second);
            noncycle[x]++;
        }
        else if(deg[i]==0)ans=1;
    }
    for(i=1;i<=n;i++)
    {
        if(deg[i]==2&&visited[i]==0)
        {
            x=dfs1(i);
            cycle[x]++;
        }
    }
    ans+=noncycle3.size()+cycle3.size();
    for(i=1;i<=n;i++)
    {
        if(noncycle[i]>0)ans++;
        if(cycle[i]>0)ans++;
    }
    printf("%d",ans);
}
