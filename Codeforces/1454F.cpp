#include<bits/stdc++.h>
using namespace std ;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
typedef unsigned long long ull ;
typedef long long ll ; 
typedef double db ; 
typedef pair<int,int> pii ; 
typedef pair<ull,ull> puu ; 
typedef pair<ll,ll> pll ;
typedef vector<int> vi ; 
typedef vector<ll> vl ;
#define mid (l+r>>1)
#define fi first
#define se second 
#define trav(it,x) for(auto&it:x) 
#define mp make_pair
#define sz(x) int()x.size()
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define up upper_bound
const ull MOD1 = 1e9+7 , MOD2 = 1e9+9 , MMOD1 = MOD1*MOD1 , MMOD2 = MOD2*MOD2; 
const ll INF = 1e18 ; 
const double pi = 3.14159265358979 ; 
const int N = 2e5+9 , inf = 1e9+7 ; 
const int mod = 1e9+7 ;///998244353

int arr[N];
vector<int> cc ; 
// rolling hash
puu hsh[N],pwhsh[N];
ull PRIME1,PRIME2; 
int str[N<<2],st[N<<2],mn[N<<2],mxl[N],mxr[N];
void updatehash(int x) {
    hsh[x] = {(hsh[x-1].fi*PRIME1+str[x])%MOD1,(hsh[x-1].se*PRIME2+str[x])%MOD2};
}
puu gethash(int l,int r) {
    int len = r-l+1 ; 
    return make_pair((hsh[r].fi - hsh[l-1].fi*pwhsh[len].fi+MMOD1)%MOD1,(hsh[r].se-hsh[l-1].se*pwhsh[len].se+MMOD2)%MOD2); 
}
void gen_hashprime() {
    PRIME1 = rand() + rand() ;
    PRIME2 = rand() + rand() ;
    pwhsh[0] = make_pair(1,1);
    for(int i=1;i<N;i++) {
        pwhsh[i] = make_pair((pwhsh[i-1].fi*PRIME1)%MOD1,(pwhsh[i-1].se*PRIME2)%MOD2);
    }
}
///end rolling hash

void add(ll &a,ll b) {
    a+=b;
    a%=mod ;
}
ll my_rand() {
    ll a = rand();
    ll b = rand();
    return a*(1ll*RAND_MAX+1)+b ; 
}
void init(int n) {
    // gen_hashprime();
    cc.clear();
    for(int i=1;i<=n+1;i++) {
        mxl[i]=mxr[i]=0;
    }
    for(int i=1;i<=4*n;i++) {
        st[i]=inf;
    }
}
void construct(int l,int r,int m) {
    if(l==r)return void(mn[m]=arr[l]);
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    mn[m]=min(mn[m<<1],mn[m<<1|1]);
}
int getmn(int l,int r,int x,int y,int m) {
    if(r<x||l>y)return inf ; 
    if(l>=x&&r<=y)return mn[m];
    return min(getmn(l,mid,x,y,m<<1),getmn(mid+1,r,x,y,m<<1|1));
}
void updatest(int l,int r,int x,int val,int m) {
    if(r<x||l>x)return ; 
    if(l==r) {
        st[m]=val;
        return ; 
    } 
    updatest(l,mid,x,val,m<<1);
    updatest(mid+1,r,x,val,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
}
int mnidx(int l,int r,int x,int y,int m) {
    if(r<x||l>y)return inf;
    if(l>=x&&r<=y)return st[m];
    return min(mnidx(l,mid,x,y,m<<1),mnidx(mid+1,r,x,y,m<<1|1));
}
void queryupdate(int idx,int m) {
    updatest(1,m,lower_bound(cc.begin(),cc.end(),arr[idx])-cc.begin()+1,idx,1);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    srand(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false),cin.tie(0);
    int t; 
    cin >> t ;
    while(t--) {
        int n ;
        cin >> n ; 
        init(n);
        for(int i=1;i<=n;i++) {
            cin >> arr[i];
            cc.push_back(arr[i]);
        }
        sort(cc.begin(),cc.end());
        cc.resize(unique(cc.begin(),cc.end())-cc.begin());
        int m = cc.size(); 
        construct(1,n,1);
        bool ans = 0 ;
        for(int i=1;i<=n;i++) {
            mxl[i]=max(mxl[i-1],arr[i]);
            mxr[n-i+1]=max(mxr[n-i+2],arr[n-i+1]);
        }
        queryupdate(n,m);
        for(int i=n-2;i>=1&&!ans;i--) {
            queryupdate(i+1,m);
            int mx = mxl[i];
            int ridx = mnidx(1,m,1,lower_bound(cc.begin(),cc.end(),mx)-cc.begin(),1);
            ridx= min(ridx,n);
            if(i<ridx-1&&mx==mxr[ridx]&&mx==getmn(1,n,i+1,ridx-1,1)) {
                ans=1;
                cout << "YES" << '\n' ; 
                cout << i << " " << ridx-i-1 << " " << n-ridx+1 << '\n' ;  
            }
            else if(i<ridx-2&&mx==mxr[ridx-1]&&mx==getmn(1,n,i+1,ridx-2,1)) {
                ans=1;
                cout << "YES" << '\n' ; 
                cout << i << " " << ridx-i-2 << " " << n-ridx+1+1 << '\n' ;  
            }
        }
        if(!ans)cout << "NO" << '\n' ;
        // return 0 ; 
    }
    return 0 ;
}