#include<bits/stdc++.h>
using namespace std ;
int a[200009];
main()
{
    int n,k,i,j ;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int co=0;
    for(i=1,j=0;i<n;i++)
    {
        while(j<i&&a[i]-a[j]>k)
        {
            j++;
        }
        while(j<i&&a[i]-a[j]<=k&&a[i]>a[j])
        {
            j++;
            co++;
        }
    }
    printf("%d",n-co);
}
