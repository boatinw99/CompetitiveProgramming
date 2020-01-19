#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
struct T
{
    int root,mn,mx,bst ;
};
vector<int> L[N],R[N];
vector<T> node[N];
T chk(int u,int par)
{
    for(auto it:node[u])
    {
        if(it.root==par)return it;
    }
    return {-1,0,0,0};
}
T dfs(int u,int par)
{
    int mnnow=u,mxnow=u,ok=1,cnt=0;
    for(auto it:L[u])
    {
        T tmp = chk(it,u) ;
        if(it!=par&&cnt==1)ok=0;
        else if(it!=par&&tmp.root==u)
        {
            if(tmp.mx>u)ok=0;
            mnnow=min(mnnow,tmp.mn);
            mxnow=max(mxnow,tmp.mx);
            ok=min(ok,tmp.bst);
            cnt++;
        }
        else if(it!=par)
        {
            tmp = dfs(it,u);
            if(tmp.mx>u)ok=0;
            mnnow=min(mnnow,tmp.mn);
            mxnow=max(mxnow,tmp.mx);
            ok=min(ok,tmp.bst);
            cnt++;
        }

    }
    cnt=0;
    for(auto it:R[u])
    {
        T tmp = chk(it,u) ;
        if(it!=par&&cnt==1)ok=0;
        else if(it!=par&&tmp.root==u)
        {
            if(tmp.mn<u)ok=0;
            mnnow=min(mnnow,tmp.mn);
            mxnow=max(mxnow,tmp.mx);
            ok=min(ok,tmp.bst);
            cnt++;
        }
        else if(it!=par)
        {
            tmp = dfs(it,u);
            if(tmp.mn<u)ok=0;
            mnnow=min(mnnow,tmp.mn);
            mxnow=max(mxnow,tmp.mx);
            ok=min(ok,tmp.bst);
            cnt++;
        }
    }
    node[u].push_back({par,mnnow,mxnow,ok});
    return {par,mnnow,mxnow,ok};
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,n,u,v,ans=0 ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        if(u<v)
        {
            R[u].emplace_back(v);
            L[v].emplace_back(u);
        }
        else
        {
            L[u].emplace_back(v);
            R[v].emplace_back(u);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(L[i].size()>2||R[i].size()>2)
        {
            cout << "IMPOSSIBLE" ;
            return 0;
        }
    }
    for(i=1;i<=n;i++)
    {
        if((L[i].size()==1&&R[i].size()==1)||(L[i].size()==1||R[i].size()==1))
        {
            T tmp = dfs(i,0);
            if(tmp.bst==1)
            {
                cout << i << " " ;
                ans++;
            }
        }
    }
    if(ans==0)cout << "IMPOSSIBLE" ;
}
