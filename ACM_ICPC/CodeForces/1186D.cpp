#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define fi first 
#define se second 
const ll INF = 1e18 ; 
const int N = 1e5+9 , inf = 1e9 , mod = 1e9+7 ;
int n,m ;
bool Y[N];
int A[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    ll sum = 0 ;
    for(int i=1;i<=n;i++)
    {
        double f ;
        cin >> f ;
        int f1=floor(f),f2=ceil(f); 
        if(f1==f2)Y[i]=1;
        A[i]=f1;
        sum+=f1;
    }
    for(int i=1;i<=n;i++)
    {
        if(sum!=0&&Y[i]==0)
        {
            sum++;
            A[i]++;
        }
    }
    for(int i=1;i<=n;i++)cout << A[i] << '\n' ;
    return 0 ;
}