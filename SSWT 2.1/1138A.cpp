#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,LOG=log2(N)+1 ;
int a[N],qs[N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,l,r ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        qs[i]=qs[i-1]+a[i];
    }
    l=0,r=1<<LOG;
    while(l+2<r)
    {
        int mid=(l+r>>1);
        if(mid>n)
        {
            r=mid;
            continue;
        }
        int mid1=mid>>1;
        bool b=0;
        //printf("aaa %d\n",mid);
        for(i=1;i+mid-1<=n;i++)
        {
            j=i+mid-1;
            int sumr=qs[j]-qs[j-mid1];
            int suml=qs[j-mid1]-qs[i-1];
            if((sumr==2*mid1&&suml==mid1)||(sumr==mid1&&suml==2*mid1))
            {
                //printf("aaa %d %d %d\n",i,j,j-mid1);
                b++;
                break;
            }
        }
        if(b)l=mid;
        else r=mid;
    }
    cout << l ;
}
