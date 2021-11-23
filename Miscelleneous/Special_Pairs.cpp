#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 , M = 1<<20 ; 
ll F[M];
int arr[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ;
    cin >> T ;
    while(T--)
    {
        int n ;
        cin >> n ; 
        memset(F,0,sizeof F);
        for(int i=1;i<=n;i++)
        {
            cin >> arr[i] ;
            F[arr[i]]++;
        }
        for(int i=1;i<M;i<<=1)
        {
            for(int mask=0;mask<M;mask++)
            {
                if(mask&i)F[mask]+=F[mask^i];
            }
        }
        ll ans = 0 ;
        for(int i=1;i<=n;i++)
        {
            ans+=F[M-1^arr[i]];
        }
        cout << ans << '\n' ; 
    }
    return 0 ;
}