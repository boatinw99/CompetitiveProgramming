#include "mooz_server.h"
#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 509 ;
vector<pii> answer ;
vector<int> g[N];
int pre[N],low[N],times=1;
void dfs0(int u,int v)
{
    pre[u]=low[u]=++times;
    for(auto it:g[u])
    {
        if(!pre[it])
        {
            dfs0(it,u);
            low[u]=min(low[u],low[it]);
            if(pre[u]<low[it])answer.emplace_back(u,it);
        }
        else if(it!=v)
        {
            low[u]=min(low[u],pre[it]);
        }
    }
}
vector<pii> find_bridge(int n)
{
    int cnt = 0 ;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(cnt>=500)break;
            vector<int> V ;
            V.clear();
            V.emplace_back(i),V.emplace_back(j);
            int ret = get_component(V);
            if(ret==1)
            {
                g[i].emplace_back(j);
                g[j].emplace_back(i);
                cnt++;
            }
        }
    }
    dfs0(1,1);
	return answer;
}
