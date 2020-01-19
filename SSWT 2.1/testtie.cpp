#include<bits/stdc++.h>
using namespace std ;
main()
{
    int a=2,b=3;
    tie(a,b)=make_pair(b-a,a);
    cout << a << " " << b ;
}
