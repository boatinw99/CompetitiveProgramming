#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int vst[N],depth[N],cnt[N];
vector<int> g[N];
vector<int> V,Vtmp; 
map<int,int> mp ; //deg 
int good = 0 ;
int countV(int u)
{
    int ret = 0 ;
    for(auto it:g[u])
    {
        if(vst[it]==0)ret++;
    }
    return ret ; 
}
void dfs0(int u,int v,int dep)
{
    if(depth[dep]!=0&&depth[dep]!=g[u].size())
    {
        good++;            
    }
    else depth[dep]=g[u].size();
    for(auto it:g[u])
    {
        if(it!=v)
        {   
            dfs0(it,u,dep+1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    for(int i=1,u,v ;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(g[i].size()==1)
        {
            vst[i]=i ; 
            cnt[i]=1 ; 
            V.push_back(i);
        }
    }
    /*
    if(V.size()==2)
    {
        cout << *V.begin() << '\n' ;
        return 0 ;
    }*/
    int root = 0 ;
    while(root==0&&!V.empty())
    {
        for(auto u:V)
        {
            if(countV(u)>1)
            {
                root = vst[u];
                break ; 
            }
            else 
            {
                for(auto it:g[u])
                {
                    if(vst[it]==0)
                    {
                        vst[it]=vst[u];
                        Vtmp.push_back(it);
                        mp[g[it].size()]++;
                    }
                    cnt[it]+=cnt[u]; 
                }
            }
        }
        sort(Vtmp.begin(),Vtmp.end(),[&](const int &a,const int &b){
            return cnt[a]<cnt[b] ; 
        });
        if(mp.size()>1)
        {
            for(auto it:Vtmp)
            {
                if(mp[g[it].size()]==1&&root==0)
                {
                    root=vst[it];
                }
            }
        }
        if(Vtmp.size()==0)
        {
            root=vst[*V.begin()];
        }
        V=Vtmp;
        Vtmp.clear();
        if(V.size()==1)root=*V.begin();
        mp.clear();
    }
    if(root==0)root=1;
    dfs0(root,root,0);
    cout << (good==0?root:-1) << '\n' ;
    return 0 ;
}