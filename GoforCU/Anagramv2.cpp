#include<bits/stdc++.h>
using namespace std;
const int N = 2009;
char a[N];
char b[N];
typedef long long ll ;
const ll prime = 2001;
ll P[256];
vector<ll> v;
main()
{
    int n,m,i,j;
    ll hash=0;
    scanf("%s %s",&a,&b);
    n=strlen(a);
    m=strlen(b);
    P[0]=1;
    for(i=1;i<255;i++)
    {
        P[i]=P[i-1]*prime;
    }
    for(i=0;i<n;i++)
    {
        hash=0;
        for(j=i;j<n;j++)
        {
            hash+=P[a[j]];
            v.push_back(hash);
        }
    }
    sort(v.begin(),v.end());
    int max1=0;
    for(i=0;i<m;i++)
    {
        hash=0;
        for(j=i;j<m;j++)
        {
            hash+=P[b[j]];
            if(binary_search(v.begin(),v.end(),hash))
            {
                max1=max(max1,j-i+1);
            }
        }
    }
    printf("%d",max1);
}
