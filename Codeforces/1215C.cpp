#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 2e5+9 , inf = 2e9 , mod = 1e9+7 ;
set<int> S[2];//ab , ba 
vector<pii> ans ; 
char A[N],B[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> A[i] ;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> B[i] ;
    }
    for(int i=1;i<=n;i++)
    {
        if(A[i]!=B[i])
        {
            if(A[i]=='a')
            {
                S[0].insert(i);
            }
            else S[1].insert(i);
        }
    }
    int x,y ; 
    while(S[0].size()>1)
    {
        x = *S[0].begin();
        S[0].erase(x);
        y = *S[0].begin();
        S[0].erase(y);
        ans.push_back({x,y});
    }
    while(S[1].size()>1)
    {
        x = *S[1].begin();
        S[1].erase(x);
        y = *S[1].begin();
        S[1].erase(y);
        ans.push_back({x,y});
    }
    if(S[0].size()==1&&S[1].size()==1)
    {
        x = *S[0].begin();
        y = *S[1].begin();
        ans.push_back({x,x});
        ans.push_back({x,y});
        S[0].erase(x);
        S[1].erase(y);
    }
    if(!S[0].empty()||!S[1].empty())
    {
        cout << "-1" << '\n' ;
        return 0 ;
    }
    else 
    {
        cout << ans.size() << '\n' ;
        for(auto it:ans)
        {
            cout << it.fi << " " << it.se << '\n' ; 
        }
    }
    return 0 ;
}