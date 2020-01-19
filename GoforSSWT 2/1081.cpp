#include<bits/stdc++.h>
using namespace std ;
vector<int>a,b,c,d;
main()
{
    int n,i,j,x ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&x);
            if(i%2==1)
            {
                if(j%2==1)
                {
                   a.push_back(x);
                }
                else b.push_back(x);
            }
            else
            {
                if(j%2==1)
                {
                    c.push_back(x);
                }
                else d.push_back(x);
            }
        }
    }
    sort(a.begin(),a.end());sort(b.begin(),b.end());
    sort(c.begin(),c.end());sort(d.begin(),d.end());
    int ans=0;
    for(j=n*n/4;j>=1;j--)
    {
        ans+=a[j-1]*b[j-1]*c[j-1]*d[j-1];
    }
    printf("%d",ans);
}
