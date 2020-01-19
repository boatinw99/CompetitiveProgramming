#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5+9 ;
int p[N],sz[N];
int find(int u)
{
    while(p[u]!=u)u=p[u];
    return u;
}
void Union(int u,int v)
{
    u=find(u),v=find(v);
    if(u==v)return ;
    if(sz[u]>sz[v])swap(u,v);
    p[u]=v;
    sz[v]+=sz[u];
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ;
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    while(m--)
    {
        int x ;
        vector<int> V ;
        V.clear();
        cin >> x ;
        for(int i=1;i<=x;i++)
        {
            int u ;
            cin >> u ;
            V.push_back(u);
        }
        for(int i=0;i<x-1;i++)
        {
            Union(V[i],V[i+1]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        //printf("aa %d \n",p[i]);
        cout << sz[find(i)] << " " ;
    }
    return 0 ;
}
