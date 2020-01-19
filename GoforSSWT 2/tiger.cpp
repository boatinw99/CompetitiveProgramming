#include<bits/stdc++.h>
using namespace std ;
const int N = 1e3+9,MAX=2e6+9 ;
pair<int,int> fire[N];
int ans[N];
int pr[MAX];
main()
{
    int n,m,i,j,x,y ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d %d",&fire[i].first,&fire[i].second);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        ans[i]=INT_MAX;
        for(j=1;j<=n;j++)
        {
            ans[i]=min(ans[i],abs(x-fire[j].first)+
                       abs(y-fire[j].second));
        }
    }
    for(i=1;i<=m;i++)
    {
        pr[ans[i]]++;
    }
    int max1=0;
    for(i=1;i<MAX;i++)max1=max(max1,pr[i]);
    printf("%d",max1);
}
