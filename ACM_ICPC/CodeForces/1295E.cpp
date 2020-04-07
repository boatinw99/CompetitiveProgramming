/*
    lazy but 2 subs 
    because of misunderstanding problem statement! (again)
*/
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mid (l+r>>1)
const ll INF = 1e18 ;
const int N = 2e5+9 ; 
ll qs[N],lazy[N<<2],st[N<<2],val[N],arr[N];
int pos[N],n;  
void construct(int l,int r,int m) {
    if(l==r) {
        st[m]=qs[l];
        return ; 
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m] = min(st[m<<1],st[m<<1|1]);
}
void pushlazy(int l,int r,int m) {
    if(lazy[m]) {
        st[m]+=lazy[m];
        if(l!=r) {
            lazy[m<<1]+=lazy[m];
            lazy[m<<1|1]+=lazy[m];
        }
        lazy[m]=0;
    }
}
void update(int l,int r,int x,int y,ll nw,int m) {
    // printf("w88 %d %d %d %d %lld\n",l,r,x,y,nw);
    pushlazy(l,r,m);
    if(r<x||l>y)return ; 
    if(l>=x&&r<=y) {
        lazy[m]+=nw;
        pushlazy(l,r,m);
        return ; 
    }
    update(l,mid,x,y,nw,m<<1);
    update(mid+1,r,x,y,nw,m<<1|1);
    st[m] = min(st[m<<1],st[m<<1|1]);
}
ll getmn(int l,int r,int x,int y,int m) {
    pushlazy(l,r,m);
    if(r<x||l>y) {
        return INF ;
    }
    if(l>=x&&r<=y) {
        return st[m];
    }
    return min(getmn(l,mid,x,y,m<<1),getmn(mid+1,r,x,y,m<<1|1));
}
int main() {
    cin >> n ; 
    for(int i=1;i<=n;i++) {
        cin >> arr[i] ;
        pos[arr[i]] = i ; 
    }
    for(int i=1;i<=n;i++) {
        cin >> val[i];
    }
    for(int i=1;i<=n;i++) {
        qs[i] = qs[i-1]+val[pos[i]];
    }
    ll ans = INF ; 
    construct(0,n,1);
    for(int i=1;i<n;i++) {
        update(0,n,arr[i],n,-val[i],1);
        update(0,n,0,arr[i]-1,val[i],1);
        ans = min(ans,getmn(0,n,0,n,1));
    }
    cout << ans << '\n' ;
    return 0; 
}