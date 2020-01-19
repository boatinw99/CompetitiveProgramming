#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
pair<int,int> a[N];
int LIS[N],*p,size;
main()
{
    int n,i,j,x ;
    while(1)
    {
        size=0;
        scanf("%d",&n);
        if(n==0)return 0 ;
        for(i=1;i<=n;i++)scanf("%d %d",&a[i].first,&a[i].second);
        sort(a+1,a+n+1);
        for(i=1;i<=n;i++)
        {
            x=a[i].second;
            p=upper_bound(LIS,LIS+size+1,x);
            LIS[p-LIS]=x;
            if(p-LIS==size+1)
            {
                size++;
            }
        }
        printf("%d\n",size);
    }

}
