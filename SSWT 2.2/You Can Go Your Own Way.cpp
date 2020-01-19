#include<bits/stdc++.h>
using namespace std ;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T,i,j,n,m ;
    char c ;
    cin >> T ;
    for(j=1;j<=T;j++)
    {
        cin >> n ;
        cout << "Case #" << j << ": ";
        for(i=1;i<=2*n-2;i++)
        {
            cin >> c ;
            cout << (c=='E'?"S":"E");
        }
        cout << '\n' ;
    }
}
