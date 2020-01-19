#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll pb = 98765431 ;
string s ;
int main()
{
    ll hash = 0 , ans = 0 ,mul=1;
    int n ;
    cin >> n >> s ;
    s+=s ;
    for(int i=0;i<n;i++)
    {
        ans=ans*pb+s[i];
    }
    for(int i=0;i<n-1;i++)mul*=pb ;
    hash=ans ;
    for(int i=n;i<2*n;i++)
    {
        hash-=mul*s[i-n];
        hash=hash*pb+s[i];
        if(hash==ans)
        {
            cout << i << '\n' ;
            return 0 ;
        }
    }

}
