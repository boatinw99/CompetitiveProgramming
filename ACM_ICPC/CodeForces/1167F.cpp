/**
 *      Author : boatinw99
 *      Date : 29_05_2019 11:53
 */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 5e5+9 , mod = 1e9+7 ;
pii a[N];
ll st[N<<2];
int lazy[N<<2];
int L[N],R[N],A[N];
void push(int l,int r,int m)
{
    if(!lazy[m])return ;
    st[m]+=1ll*(r-l+1)*lazy[m];
    if(l<r)
    {
        lazy[m<<1]+=lazy[m];
        lazy[m<<1|1]+=lazy[m];
    }
    lazy[m]=0;
}
void update(int l,int r,int x,int y,int cst,int m)
{
    push(l,r,m);
    if(r<x||l>y)return ;
    if(l>=x&&r<=y)
    {
        lazy[m]+=cst ;
        push(l,r,m);
        return ;
    }
    update(l,mid,x,y,cst,m<<1);
    update(mid+1,r,x,y,cst,m<<1|1);
    st[m]=st[m<<1]+st[m<<1|1];
}
ll getsum(int l,int r,int x,int y,int m)
{
    push(l,r,m);
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return (getsum(l,mid,x,y,m<<1)+getsum(mid+1,r,x,y,m<<1|1));
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].fi ;
        a[i].se = i ;
        A[i]=a[i].fi;
    }
    sort(a+1,a+1+n);
    int ans = 0 ;
    for(int i=1;i<=n;i++)
    {
        int idx = a[i].se ;
        ll sum = getsum(1,n,1,idx-1,1)-1ll*(idx-1)*getsum(1,n,idx,idx,1);
        sum%=mod;
        update(1,n,1,idx,1,1);
        L[idx]=sum ;
    }
    memset(st,0,sizeof st);
    memset(lazy,0,sizeof lazy);
    for(int i=1;i<=n;i++)
    {
        int idx = a[i].se ;
        ll sum = getsum(1,n,idx+1,n,1)-1ll*(n-idx)*getsum(1,n,idx,idx,1);
        sum%=mod ;
        update(1,n,idx,n,1,1);
        R[idx]=sum;
    }
    for(int i=1;i<=n;i++)
    {
        int sum = (1ll*L[i]*(n-i+1)+1ll*R[i]*i)%mod;
        sum=(sum+1ll*(n-i+1)*i)%mod;
        ans=(ans+1ll*sum*A[i])%mod;
    }
    cout << ans << '\n' ;
}
