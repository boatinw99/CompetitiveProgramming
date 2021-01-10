#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ; 
#define fi first
#define se second
const ll INF = 1e18 ; 
const int N = 1e6+9 , mod = 1e9+7 , inf = 1e9 ;
string A[N];
vector<int> V[N][5];
vector<int> S[N];
vector<pii> good ;  
vector<pair<pii,pii> > ans ;  
char C[5]={'a','e','i','o','u'} ;
int pos[N];
void push(int x)
{
    int last = 0 , cnt = 0 ; 
    int n = A[x].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(C[j]==A[x][i])cnt++,last=j;
        }
    }
    V[cnt][last].push_back(x);
}
void print(int x)
{
    cout << A[x] ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    for(int i=0;i<5;i++)pos[C[i]]=i;
    for(int i=1;i<=n;i++)
    {
        cin >> A[i] ;
        push(i);
    }
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<5;j++)
        {
            while(V[i][j].size()>=2)
            {
                int x = V[i][j].back();
                V[i][j].pop_back();
                int y = V[i][j].back();
                V[i][j].pop_back();
                good.emplace_back(x,y);
            }
            if(V[i][j].size()==1)
            {
                S[i].emplace_back(V[i][j].back());
            }
        }
    }
    for(int i=1;i<N;i++)
    {
        while(S[i].size()>=2&&!good.empty())
        {
            pii X = good.back();
            good.pop_back();
            int x = S[i].back();
            S[i].pop_back();
            int y = S[i].back();
            S[i].pop_back();
            ans.push_back({{x,y},X});
        }
    }
    while(good.size()>=2)
    {
        pii X = good.back();
        good.pop_back();
        pii Y = good.back();
        good.pop_back();
        ans.push_back({X,Y});
    }
    cout << ans.size() << '\n' ;
    for(auto it:ans)
    {
        print(it.fi.fi);
        cout << " " ;
        print(it.se.fi);
        cout << '\n' ;
        print(it.fi.se);
        cout << " " ;
        print(it.se.se);
        cout << '\n' ;
    }
    return 0 ;
}