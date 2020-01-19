#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 1e5+9 ; 
int pos[N],arr[N];
pii ans[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ; 
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        pos[i]=i;
        arr[i]=i;
        ans[i]={i,i};
    }
    while(m--)
    {
        int u ; 
        cin >> u ;
        int idx = pos[u];
        if(idx>1)
        {
            swap(arr[idx],arr[idx-1]);
            pos[arr[idx]]=idx;
            pos[arr[idx-1]]=idx-1;
            ans[arr[idx]].fi=min(ans[arr[idx]].fi,idx);
            ans[arr[idx]].se=max(ans[arr[idx]].se,idx);
            ans[arr[idx-1]].fi=min(ans[arr[idx-1]].fi,idx-1);
            ans[arr[idx-1]].se=max(ans[arr[idx-1]].se,idx-1);
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << ans[i].fi << " " << ans[i].se << '\n' ;
    }
    return 0 ;
}