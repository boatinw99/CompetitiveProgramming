/*
    WRONG_ALGO #2 
    date 05-04-20
    Hints : segtree 
*/
#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
#define mid (l+r>>1)
const int N = 3e5+9 ; 
int n,arr[N],pos[N];
pii st[N<<2];
pii operate(pii a,pii b) {
    /// val , bomb 
    int tmp = min(a.fi,b.se);
    return {a.fi+b.fi-tmp,a.se+b.se-tmp};
}
void update(int l,int r,int x,pii nw,int m) {
    if(r<x||l>x) {
        return ; 
    }
    if(l==r) {
        st[m].fi+=nw.fi ;
        st[m].se+=nw.se ;
        if(st[m].se==1&&st[m].fi==1) {
            st[m] = {0,0};
        }
        return ; 
    }
    update(l,mid,x,nw,m<<1);
    update(mid+1,r,x,nw,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
pii getans(int l,int r,int x,int y,int m) {
    if(r<x||l>y)return {0,0} ; 
    if(l>=x&&r<=y) {
        return st[m];
    }
    return operate(getans(l,mid,x,y,m<<1),getans(mid+1,r,x,y,m<<1|1));
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ; 
    for(int i=1;i<=n;i++) {
        cin >> arr[i]; 
        pos[arr[i]]=i;
    }
    int ans = n ; 
    update(1,n,pos[n],{1,0},1);
    for(int i=1,x ;i<=n;i++) {
        cout << ans << " ";
        cin >> x ;
        update(1,n,x,{0,1},1);
        while(getans(1,n,1,n,1).fi<=0) {
            ans--;
            update(1,n,pos[ans],{1,0},1);
        }
    }
    return 0 ; 
}