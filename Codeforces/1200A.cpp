#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<ll,ll> pll ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll INF = 1e18 ;
const int N = 1e5+9 , inf = 1e9 , mod = 1e9+7 ;
bool A[11];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        char c ;
        cin >> c ;
        if(c=='L')
        {
            for(int j=0;j<10;j++)
            {
                if(A[j]==0)
                {
                    A[j]++;
                    break;
                }
            }
        }
        else if(c=='R') 
        {
            for(int j=9;j>=0;j--)
            {
                if(A[j]==0)
                {
                    A[j]++;
                    break;
                }
            }
        }
        else 
        {
            A[c-'0']=0;
        }
    }
    for(int i=0;i<10;i++)
    {
        cout << A[i] ;
    }
    return 0 ;
}