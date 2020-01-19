#include<bits/stdc++.h>
using namespace std ;
const int N = 2009 , M = 2e5+9 ,inf = 2e9 ;
queue<int> q;
vector<int> L,R,g[N],unselected;
int sieve[M],match[N],dist[N],selected[N],n,m ;
bool use[N];
void preprocess()
{
    for(int i=2;i<M;i++)if(!sieve[i])for(int j=i+i;j<M;j+=i)sieve[j]=i ;
}
bool bfs()
{
    for(int i=1;i<=n;i++)
    {
        if(!match[i])
        {
            dist[i]=0;
            q.push(i);
        }
        else dist[i]=inf ;
    }
    dist[0]=inf ;
    while(!q.empty())
    {
        int u = q.front() ; q.pop();
        if(!u)continue ;
        for(auto it:g[u])
        {
            if(dist[match[it]]==inf)
            {
                dist[match[it]]=dist[u]+1;
                q.push(match[it]);
            }
        }
    }
    return dist[0]!=inf ;
}
bool dfs0(int u)
{
    if(!u)return 1 ;
    for(auto it:g[u])
    {
        if(dist[match[it]]==dist[u]+1)
        {
            if(dfs0(match[it]))
            {
                match[it]=u;
                match[u]=it;
                return 1 ;
            }

        }
    }
    dist[u]=inf ;
    return 0 ;
}
void hopcroft_carp()
{
    while(bfs())for(int i=1;i<=n;i++)if(!match[i]&&dfs0(i));
}
int main()
{
    int P,x ;
    preprocess();
    cin >> P ;
    for(int i=1;i<=P;i++)
    {
        cin >> x ;
        if(x&1)L.emplace_back(x);
        else R.emplace_back(x);
    }
    n=L.size(),m=R.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)if(!sieve[L[i]+R[j]])g[i+1].emplace_back(j+n+1);
    }
    hopcroft_carp();
    for(int i=1;i<=n;i++)
    {
        if(match[i])selected[i]++;
        else unselected.emplace_back(i);
    }
    while(!unselected.empty())
    {
        int u = unselected.back();
        unselected.pop_back();
        for(auto it:g[u])
        {
            if(!selected[it])
            {
                selected[it]++;
                selected[match[it]]=0;
                unselected.emplace_back(match[it]);
            }
        }
    }
    int cnt = 0 ;
    for(int i=1;i<=n;i++)if(match[i])cnt++;
    cout << cnt << '\n' ;
    for(int i=1;i<=n;i++)if(selected[i])cout << L[i-1] << " " ;
    for(int i=n+1;i<=n+m;i++)if(selected[i])cout << R[i-n-1] << " " ;
    return 0 ;
}
