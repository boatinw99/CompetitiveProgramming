#include<bits/stdc++.h>
using namespace std ;
const int N = 1009;
int a[2*N] ;
map<int,int> m ;
map<int,int> ::iterator it;
void pr(int dis,int n)
{
    int x,y,i ;
    for(i=1;i<=2*n;i++)m[a[i]]++;
    printf("%d\n",dis);
    for(it=m.begin();it!=m.end();it++)
    {
        x=it->first ; y=it->first+dis;
        while(m[x]>0)
        {
            m[y]--;
            m[x]--;
            printf("%d ",y);
        }
    }
}
main()
{
    int n,i,j,k,x,y,dis ;
    scanf("%d",&n);
    for(i=1;i<=2*n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+2*n);
    for(i=2;i<=n+1;i++)
    {
        dis=a[i]-a[1];
        for(k=1;k<=2*n;k++)m[a[k]]++;
        k=2*n;
        for(it=m.begin();it!=m.end();it++)
        {
            x=it->first; y=it->first+dis;
            while(it->second>0)
            {
                if(m[y]>0)
                {
                    m[x]--;
                    m[y]--;
                    k-=2;
                }
                else break ;
            }
            if(it->second>0)break;
        }
        for(it=m.begin();it!=m.end();it++)it->second=0;
        if(k==0)
        {
            pr(dis,n);
            return 0;
        }
    }
    printf("-1");
}
