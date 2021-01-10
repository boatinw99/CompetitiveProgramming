#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 1e5+9 , inf = 1e9 ; 
vector<int> V ;
pii point[N];
long double getl(pii x)
{
    long double tmp = x.fi*x.fi+x.se*x.se; 
    tmp = sqrt(tmp);
    return tmp;    
}
ll dott(pii a,pii b)
{
    return a.fi*b.fi+a.se*b.se ;
}
bool comp(pii p1,pii p2,pii p3,pii p4)
{
    auto check1 = 1.0*dott(p1,p2)*getl(p3)*getl(p4); 
    auto check2 = 1.0*dott(p3,p4)*getl(p1)*getl(p2) ;
    return check1 > check2 ;
}
bool top(pii a)
{
    return a.se<0||a.se==0&&a.fi<0;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        V.emplace_back(i);
        cin >> point[i].fi >> point[i].se ;
    }
    sort(V.begin(),V.end(),[&](int i,int j){
        pii a = point[i];
        pii b = point[j];
        bool ta = top(a);
        bool tb = top(b);
        if(ta!=tb)return ta;
        return a.fi*b.se-a.se*b.fi>0;
    });
    pii ans = {1,2} ;
    for(int i=0;i<n;i++)
    {
        int x = V[i] , y = V[(i+1)%n];
        if(comp(point[x],point[y],point[ans.fi],point[ans.se]))ans={x,y};
    }
    cout << ans.fi << " " << ans.se << '\n' ;
}