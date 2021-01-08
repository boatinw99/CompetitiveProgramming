#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se escond 
const int N = 1e4+9 , mod = 1e9+7 ; 
double a[N],qs[N];
int main()
{
    //ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    scanf("%d %d",&n,&m);
    assert(n<=10000&&m<=10000);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&a[i]);
        assert(a[i]<=1500);
        qs[i]=qs[i-1]+a[i];
    }
    if(n-m+1<=0)
    {
        printf("0");
        return 0 ;
    }
    printf("%d\n",n-m+1);
    for(int i=1;i<=n-m+1;i++)
    {
        printf("%.6lf ",(qs[i+m-1]-qs[i-1])/m); 
    }
    return 0 ;
}