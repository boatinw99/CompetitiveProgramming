#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5+9 ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
#define mid (l+r>>1)
#define fi first
#define se second 
pli Q[N];
int ans[N],A[N],arr[N];
int n,m,q,f[N];
void update(int idx,int val)
{
    for(;idx<=n;idx+=idx&-idx)f[idx]+=val;
}
int getval(int idx)
{
    int sum = 0 ;
    for(;idx;idx-=idx&-idx)sum+=f[idx];
    return sum ;
}
int getans(ll x,int sz)
{
    x=(x-1)%sz+1;
    int l=0,r=n;
    while(l+1<r)
    {
        if(getval(mid)<x)l=mid;
        else r=mid;
    }
    return r ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> m >> n >> q ;
    for(int i=1,x ;i<=m;i++)
    {
        cin >> x ;
        A[x]++;
    }
    for(int i=1;i<=n;i++)arr[i]=i ;
    for(int i=1;i<=q;i++)
    {
        cin >> Q[i].fi ;
        Q[i].fi-=m ; 
        Q[i].se=i;
    }
    sort(Q+1,Q+1+q);
    sort(arr+1,arr+1+n,[&](const int a,const int b){
        if(A[a]!=A[b])return A[a]<A[b];
        return a<b ; 
    });
    int sum = A[arr[1]] ;
    update(arr[1],1);
    for(int i=1,r=1;i<=q;i++)
    {
        while(r<n&&1ll*A[arr[r+1]]*r-sum<Q[i].fi)
        {
            r++;
            update(arr[r],1);
            sum+=A[arr[r]];
        }
        ans[Q[i].se]=getans(Q[i].fi-1ll*A[arr[r]]*r+sum,r);
    }
    for(int i=1;i<=q;i++)
    {
        cout << ans[i] << '\n' ;
    }
    return 0 ;
}