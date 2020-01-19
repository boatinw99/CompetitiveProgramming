#include<bits/stdc++.h>
using namespace std ;
const int N = 200009;
int a[N];
bool findans(int i,int j,int m,int k)
{
    int pr=0,numb=1;
    for(i;i<=j;i++)
    {
        if(pr+a[i]>k)
        {
            pr=0;
            numb++;
        }
        pr+=a[i];
    }
    if(numb<=m)return 0;
    return 1;
}
main()
{
    int n,m,k,l,r,i,j ;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    bool b=0;
    l=0; r=n;
    while(l+1<r)
    {
        int mid=l+r>>1;
        b=findans(mid,n,m,k);
        //printf("%d->%d\n",mid,b);
        if(b==0)
        {
            r=mid;
        }
        else l=mid;
    }
    printf("%d",n-r+1);
}
