#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll pb = 98765431 ;
const int N = 1e6+9 ;
ll p[N];
string s ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int t ;
    cin >> t ;
    p[0]=1 ;
    for(int i=1;i<N;i++)p[i]=p[i-1]*pb;
    while(t--)
    {
        cin >> s ;
        int n = s.size() , l = 0 , r = n-1 , ans = 0 ;
        ll hashl = 0 , hashr = 0 ;
        for(int i=0,j=n-1;i<j;i++,j--)
        {
            hashl=hashl*p[1]+s[i];
            hashr+=s[j]*p[r-j];
            if(hashl==hashr)
            {
                ans+=2,l=i+1,r=j-1;
                hashl=hashr=0 ;
            }
        }
        if(n&1||hashl!=0)ans++;
        cout << ans << '\n' ;
    }

    return 0 ;
}
