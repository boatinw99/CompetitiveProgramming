#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , M = 1e6+9 ;
vector<int> depth[M];
int a[N],ans[N],par[N],len[N],rnk[N];
bool vst[N];
int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
void Union(int u,int v)
{
    int pu=find(u),pv=find(v);
    if(rnk[pu]>=rnk[pv])
    {
        rnk[pu]+=rnk[pv];
        len[pu]+=len[pv];
        ///len[pv]=0; for bug
        par[pv]=pu ;
    }
    else
    {
        rnk[pv]+=rnk[pu];
        len[pv]+=len[pu];
        par[pu]=pv;
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,w ;
    cin >> n >> w ;
    w++;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        par[i]=i ;
        len[i]=1 ;
        rnk[i]=i ;
        depth[a[i]].emplace_back(i);
    }
    for(i=M-1;i>=0;i--)
    {
        for(auto it:depth[i])
        {
            if(vst[it-1])
            {
                Union(it-1,it);
            }
            if(vst[it+1])
            {
                Union(it+1,it);
            }
            vst[it]++;
        }
        for(auto it:depth[i])
        {
            int pu=find(it);
            ans[len[pu]]=max(ans[len[pu]],i);
            //printf("aaa %d | %d \n",len[pu],i);
        }
        //return 0 ;
    }
    if(w>0)
    {
        cout << (ans[w]?ans[w]:-1);
        return 0 ;
    }
    else
    {
        for(i=2;i<=n+1;i++)
        {
            cout << (ans[i]?ans[i]:-1) << " " ;
        }
    }
}
