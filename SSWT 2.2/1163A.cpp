#include<bits/stdc++.h>
using namespace std ;
const int N = 1009 ;
int a[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,cc=0;
    cin >> n >> m ;
    if(m==0)
    {
        cout << "1" ;
        return 0 ;
    }
    for(int i=1;i<n&&m;i+=2)
    {
        m--;
        cc++;
    }
    if(n&1)m--;
    if(m>0)
    {
        cc-=m;
    }
    cout << cc ;

}
