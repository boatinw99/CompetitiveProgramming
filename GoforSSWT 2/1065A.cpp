#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main()
{
    ll t,s,a,b,c;
    scanf("%I64d",&t);
    while(t--)
    {
        cin >> s >> a >>  b >> c;
        ll t = s/c;
        t+=(t/a)*b;
        printf("%I64d\n",t);
    }

}
