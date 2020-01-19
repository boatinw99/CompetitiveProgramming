#include<bits/stdc++.h>
using namespace std ;
const int N = 1009;
pair<int,int> a[N];
main()
{
    int n,k,i,j ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    for(i=1,j=1;i<=n&&j<=n;)
    {
        if(a[i].first>=a[j].second)
        {
            a[i].first-=a[j].second;
            a[j].second=0;

        }
        else if(a[i].first<a[j].second)
        {
            a[j].second-=a[i].first;
            a[i].first=0;
        }
        while(a[i].first==0&&i<=n)i++;
        while(a[j].second==0&&j<=n)j++;
        if((j>n&&i<=n)||(j-i>k&&j>i)||(i-j>k&&i>j)||(i>n&&j<=n))
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}
