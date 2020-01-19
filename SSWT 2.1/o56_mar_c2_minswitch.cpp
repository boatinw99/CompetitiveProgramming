#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 1e4+9,K=20;
vector<int> g[N],ans,st,mark[N];
bool vst[N];
int cnt=0,n;
void dfs(int x)
{
    if(cnt>K)return ;
    if(x==n+1)
    {
        if(st.size()<ans.size())ans=st;
        return ;
    }
    if(vst[x]==1)dfs(x+1);
    else
    {
        if(g[x].size()==1)
        {
            int tmp=0;
            for(auto it:g[x])tmp=it;
            if(vst[tmp]==1)
            {
                dfs(x+1);
                return ;
            }
            cnt++;
            st.push_back(tmp);
            vst[tmp]++;
            dfs(x+1);
            st.pop_back();
            vst[tmp]=0;
            cnt--;
        }
        else if(g[x].size()>K)
        {
            cnt++;
            vst[x]++;
            st.push_back(x);
            dfs(x+1);
            cnt--;
            vst[x]=0;
            st.pop_back();
        }
        else
        {
            int num=0;
            for(auto it:g[x])if(vst[it]==0)
            {
                num++;
                break;
            }
            if(num)
            {
                cnt++;
                vst[x]++;
                st.push_back(x);
                dfs(x+1);
                cnt--;
                vst[x]=0;
                st.pop_back();
            }
            for(auto it:g[x])
            {
                if(vst[it]==0)
                {
                    cnt++;
                    vst[it]++;
                    mark[x].emplace_back(it);
                    st.push_back(it);
                }
            }
            dfs(x+1);
            for(auto it:mark[x])
            {
                cnt--;
                vst[it]=0;
                st.pop_back();
            }
            mark[x].clear();
        }
    }
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int m,i,j,u,v ;
    cin >> n >> m ;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=0;i<21;i++)ans.push_back(-1);
    dfs(1);
    cout << ans.size() << '\n';
    for(auto it:ans)cout << it << '\n' ;
}
