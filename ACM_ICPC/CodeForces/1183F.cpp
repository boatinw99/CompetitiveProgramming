#include<bits/stdc++.h>
using namespace std ;
vector<int> V,U ; 
int mx = 0,n,m ; 
bool half = 0 ; 
void init()
{
    V.clear();
    U.clear();
    half = 0 ;
    mx = 0 ;
}
bool checkf(int x,int y)
{
    if(x<y)swap(x,y);
    return (x%y)!=0 ; 
}
bool check(int x,int y,int z)
{
    bool ret = 1 ; 
    ret=min(ret,checkf(x,y));
    ret=min(ret,checkf(x,z));
    ret=min(ret,checkf(y,z));
    return ret ; 
}
int find2(int x,int y)
{
    for(int i=n-1;i>=0;i--)
    {
        if(check(x,y,V[i]))
        {
            return V[i];
        }
    }
    return 0 ;
}
int find1(int x)
{
    for(int i=n-1;i>=0;i--)
    {
        if(checkf(x,V[i]))
        {
            return find2(x,V[i])+V[i];
        }
    }
    return 0 ;
}
int solve()
{
    int ans = 0 ;
    if(m>=3)
    {
        if(check(U[m-1],U[m-2],U[m-3]))return U[m-1]+U[m-2]+U[m-3];
    }
    if(m>=2)
    {
        int y=U[m-2];
        ans=max(ans,y+find1(y));
    }
    if(half)
    {
        ans=max(ans,mx/2+find1(mx/2));
    }
    ans=max(ans,mx+find1(mx));
    return ans ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int q ;
    cin >> q ;
    while(q--)
    {
        init();
        cin >> n ;
        for(int i=1,u ;i<=n;i++)
        {
            cin >> u ;
            V.push_back(u);
        }
        sort(V.begin(),V.end());
        mx = V.back();
        for(auto it:V)
        {
            if(it*2==mx)half++;
            if(it>mx/3&&checkf(mx,it))U.push_back(it);
        }
        U.push_back(mx);
        m = U.size();
        cout << solve() << '\n' ; 
    }
    return 0 ;
}