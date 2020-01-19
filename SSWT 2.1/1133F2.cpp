#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ;
int par[N],rnk[N];
vector<int> g[N],ans;
queue<int> q;
int find(int u)
{
    return u==par[u]?u:par[u]=find(par[u]);
}
bool Union(int x,int y)
{
    int px=find(x),py=find(y);
    if(px==py)return 0;
    if(rnk[x]>=rnk[y])rnk[x]+=rnk[y],par[py]=px;
    else rnk[y]+=rnk[x],par[px]=py;
    return 1 ;
}
void clearq()
{
    for(;!q.empty();)
    {
        int x=q.front();
        q.pop();
        for(auto it:g[x])
        {
            if(Union(it,x))
            {
                cout << it << " " << x << '\n' ;
                q.push(it);
            }
        }
    }
}
main()
{
    int n,m,i,j,u,v,k ;
    cin >> n >> m >> k ;
    int cc=n ;
    while(m--)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)par[i]=i;
    for(i=2;i<=n;i++)
    {
        for(auto it:g[i])
        {
            if(it!=1)
            {
                if(Union(i,it))cc--;
            }
        }
    }
    int cnt=0;
    for(auto it:g[1])
    {
        if(Union(1,it))
        {
            ans.push_back(it);
            cc--;
            cnt++;
        }
    }
    if(cc==1&&cnt<=k&&g[1].size()>=k)
    {
        cout << "YES" << '\n' ;
        for(i=1;i<=n;i++)par[i]=i,rnk[i]=1;
        for(auto it:ans)
        {
            cout << "1 " << it << '\n';
            Union(1,it);
            q.push(it);
            k--;
        }
        for(auto it:g[1])
        {
            if(k&&Union(1,it))
            {
                cout << "1 " << it << '\n' ;
                k--;
                q.push(it);
            }
        }
        clearq();
        return 0 ;
    }
    cout << "NO" ;

}
