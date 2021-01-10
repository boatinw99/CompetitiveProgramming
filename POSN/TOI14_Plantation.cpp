#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ; 
pii A[N];
int n ; 
double dist(pii a,pii b)
{
    double x = (a.fi-b.fi) , y = (a.se-b.se);
    return sqrt(x*x+y*y);
}
double solve(int l,int r)
{
    double d = 1e9;
    if(r-l+1<=3){
        for(int i=l;i<r;i++){
            for(int j=i+1;j<=r;j++)d=min(d,dist(A[i],A[j]));
        }
        return d ; 
    }
    int mid = l+r >> 1 ;
    double dl = solve(l,mid) ;
    double dr = solve(mid+1,r) ;
    d = min(dl,dr);
    vector<pii> V ;
    for(int i=l;i<=r;i++)if(abs(A[i].fi-A[mid].fi)<d)V.push_back(A[i]);
    sort(V.begin(),V.end(),[&](const pii a,const pii b){
        if(a.se==b.se)return a.fi<b.fi ; 
        return a.se<b.se ; 
    });
    int sz = V.size(); 
    for(int i=0;i<sz;i++)
    {
        for(int j=i+1;j<sz&&V[j].se-V[i].se<d;j++)
        {
            d=min(d,dist(V[i],V[j]));
        }
    }
    return d ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ;
    while(T--)
    {
        int r,d ; 
        cin >> n >> r >> d ;
        for(int i=1;i<=n;i++)
        {
            cin >> A[i].fi >> A[i].se ; 
        }
        sort(A+1,A+1+n);
        cout << ((solve(1,n)<2*r+d)?"N":"Y") << '\n' ;
    }
}