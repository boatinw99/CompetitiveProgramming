#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ; 
vector<int> spec[N<<1];
int n,m,A[N],all=0; 
bool use[N];
bool check(int x)
{ 
    memset(use,0,sizeof use);
    int tot = x , rmn = all , money = x ;  
    for(int i=x;i>=1;i--)
    {
        for(auto it:spec[i])
        {
            if(!use[it]++)
            {
                money = min(money,i);
                int tmp = min(A[it],money);
                rmn-=tmp ;
                money-=tmp ;
                tot-=tmp ; 
            }
        }   
    }
    return tot>=(rmn*2);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ; 
    for(int i=1;i<=n;i++)cin >> A[i],all+=A[i]; 
    for(int i=1;i<=m;i++)
    {
        int di,ti ; 
        cin >> di >> ti ; 
        spec[di].emplace_back(ti);
    }
    int l = -1 , r = 4e5+9 ; 
    while(l+1<r)
    {
        int mid = l+r >> 1 ;
        if(check(mid))r=mid ;
        else l=mid ; 
    }
    cout << r << '\n' ; 
    return 0 ;
}