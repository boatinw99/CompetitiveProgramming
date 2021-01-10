#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const int N = 2e5+9 ; 
const int mod = 998244353 ; 
#define mid (l+r>>1)
#define fi first
#define se second 
int n,m,arr[N],b[N],st[N<<2],sz;
map<int,int> biject ; 
map<int,vector<int>> mp ;
vector<int> cc ; 
void update(int l,int r,int x,int y,int m) {
    if(r<x||l>x) {
        return ; 
    }
    if(l==r) {
        st[m] = y ; 
        // printf("check update %d %d %d %d \n",l,r,x,y);
        return ; 
    }
    update(l,mid,x,y,m<<1);
    update(mid+1,r,x,y,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
int getrightmost(int l,int r,int x,int y,int m) {
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return max(getrightmost(l,mid,x,y,m<<1),getrightmost(mid+1,r,x,y,m<<1|1));
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ; 
    for(int i=1;i<=n;i++) {
        cin >> arr[i] ;  
        mp[arr[i]].push_back(i);
        cc.push_back(arr[i]);
    }
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    sz = cc.size();
    for(int i=0;i<sz;i++) {
        biject[cc[i]] = i+1 ; 
    }
    for(int i=1;i<=m;i++) {
        cin >> b[i] ; 
    }
    for(int i=1;i<=n;i++) {
        if(arr[i]<b[1]) {
            cout << 0 << '\n' ; 
            return 0 ; 
        }
    } 
    for(int i=1;i<=m;i++) {
        if(mp[b[i]].empty()) {
            cout << 0 << '\n' ;
            return 0 ; 
        }
    }
    ll prev = 1 ; 
    int previdx = 0 ; 
    for(int i=2;i<=m;i++) {
        int rgmost = *mp[b[i]].rbegin();
        // printf("whatt %d \n",rgmost);
        if(rgmost<previdx) {
            cout << 0 << '\n' ;
            return 0; 
        }
        while(previdx<rgmost) {
            previdx++;
            update(1,sz,biject[arr[previdx]],previdx,1);
            // printf("update %d %d \n",biject[arr[previdx]],previdx);
        }
        int idxval = biject[arr[rgmost]];
        int pos = getrightmost(1,sz,1,idxval-1,1);
        prev = prev*(rgmost-pos)%mod ; 
        // printf("check idxval=%d pos=%d prev=%lld rgmost=%d \n",idxval,pos,prev,rgmost);
        if(getrightmost(1,sz,1,biject[arr[*mp[b[i-1]].rbegin()]],1)>*mp[b[i-1]].rbegin()) {
            cout << 0 << '\n' ;
            return 0 ;
        }
    }
    while(previdx<n) {
        previdx++;
        if(arr[previdx]<b[m]) {
            cout << 0 << '\n' ;
            return 0 ; 
        }
    }
    cout << prev << '\n' ;  
    return 0 ; 
}