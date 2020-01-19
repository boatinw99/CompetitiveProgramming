#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
typedef long long ll ;
int a[N],*p;
ll qs[N];
main()
{
    int m,n,i,j,k ;
    ll R=0,K,L ;
    scanf("%d",&m);
    while(m--)
    {
        R=0;
        bool b=0 ;
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        for(i=1;i<=n;i++)qs[i]=a[i]+qs[i-1];
        for(k=n;k>0;k--)
        {
            R+=a[k];
            K=(n-k+1);
            p=upper_bound(a+1,a+k,K);
            p--;
            j=p-a;
            L=qs[j];
            if(R>K*(K-1)+L+((k-j-1)*K))
            {
                b++;
                break;
            }
        }
        printf("%s\n",(b==1||R%2)?("No"):("Yes"));
    }
}
