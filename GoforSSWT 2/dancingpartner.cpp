#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
pair<int,int> A[N]; //Hi,Ai;
pair<int,int> B[N]; //Kj,Bi;
int slideup[N],slidedown[N];
int ans[N];
main()
{
    int n,i,j ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&A[i].first,&A[i].second);
    }
    slideup[0]=-2e9;
    for(i=1;i<=n;i++)
    {
        ans[i]=INT_MIN;
        scanf("%d %d",&B[i].first,&B[i].second);
        slideup[i]=B[i].first+B[i].second ;
        slideup[i]=max(slideup[i],slideup[i-1]);
        slidedown[i]=B[i].second-B[i].first ;
    }
    for(i=n-1;i>0;i--)
    {
        slidedown[i]=max(slidedown[i],slidedown[i+1]);
    }
    for(i=n,j=n;i>0&&j>0;i--)
    {
        while(j>0&&A[i].first<B[j].first)j--;
        if(j<0)break;
        ans[i]=A[i].second-A[i].first+slideup[j];
    }
    for(i=1,j=1;i<=n;i++)
    {
        while(j<=n&&A[i].first>B[j].first)j++;
        if(j>n)break;
        ans[i]=max(ans[i],A[i].first+A[i].second+slidedown[j]);
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\n",ans[i]);
    }
}
