#include<bits/stdc++.h>
using namespace std ;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,A,B,T,t;
    cin >> T ;
    for(t=1;t<=T;t++)
    {
        cin >> n ;
        A=n,B=0 ;
        for(i=1;i<=n;i*=10)
        {
            if((n/i)%10==4)
            {
                A-=2*i;
                B+=2*i;
            }
        }
        cout << "Case #" << t << ": " << A << " " << B << '\n' ;
    }

}
