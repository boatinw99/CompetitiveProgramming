#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
int n,w;
const int N = 29;
int a[N];
ll findans(int i,int k,ll Wi)
{
    ll x=Wi*2-(a[k]*(1<<i))+(1<<i);
    if(x<0)return -1;
    if(k==1)return x;
    else return findans(i+1,k-1,x);
}
main()
{
    int i,j ;
    scanf("%d %d",&n,&w);
    for(i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%lld",findans(0,n-1,w));
}
