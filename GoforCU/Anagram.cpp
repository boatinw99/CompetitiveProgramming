#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll MOD=1e16+2;
map<ll,int> m ;
ll prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
main()
{
    int i,j,k;
    ll d ;
    string A,B;
    cin >> A >> B;
    for(k=A.length();k>0;k--)
    {
        d=1;
        for(i=0;i<A.length();i++)
        {
            d*=prime[A[i]-'A'];
            d%=MOD;
            if(i-k+1>0)d/=prime[A[i-k]-'A'];
            if(i-k+1>=0)
            {
               m[d]++;
            }
        }
        d=1;
        for(i=0;i<B.length();i++)
        {
            d*=prime[B[i]-'A'];
            if(i-k+1>0)d/=prime[B[i-k]-'A'];
            d%=MOD;
            if(i-k+1>=0&&m[d]>0)
            {
               printf("%d ",k);
               return 0;
            }

        }
        m.clear();
    }
    printf("0");;
}
