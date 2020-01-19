#include "traffic.h"
#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
int a[8];
int n,k;
int dist(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
main()
{
    int i,j,cnt=0 ;
    traffic_init(&n, &k);
    for(j=1;j<=n&&k;j++)
    {
        int tmp = traffic_query(1,j,n,j);
        if(tmp>n-1)
        {
            int l=1,r=n ;
            while(l+1<r)
            {
                if(traffic_query(l,j,mid,j)>dist(l,j,mid,j))r=mid;
                else l=mid ;
            }
            a[cnt]=l,a[cnt+1]=j,a[cnt+2]=r,a[cnt+3]=j;
            cnt+=4;
            k--;
            if(tmp==n);
            else
            {
                l=r;
                r=n;
                while(l+1<r)
                {
                    if(traffic_query(l,j,mid,j)>dist(l,j,mid,j))r=mid;
                    else l=mid ;
                }
                a[4]=l,a[5]=j,a[6]=r,a[7]=j;
                break;
            }
        }
        tmp = traffic_query(j,1,j,n);
        if(tmp>n-1)
        {
            int l=1,r=n ;
            while(l+1<r)
            {
                if(traffic_query(j,l,j,mid)>dist(j,l,j,mid))r=mid;
                else l=mid ;
            }
            a[cnt]=j,a[cnt+1]=r,a[cnt+2]=j,a[cnt+3]=l;
            cnt+=4;
            l=r;
            r=n;
            k--;
            if(tmp==n);
            else
            {
                while(l+1<r)
                {
                    if(traffic_query(j,l,j,mid)>dist(j,l,j,mid))r=mid;
                    else l=mid ;
                }
                a[4]=j,a[5]=r,a[6]=j,a[7]=l;
                k++;
            }
        }
    }
    traffic_report(a[0],a[1],a[2],a[3], a[4],a[5],a[6],a[7]);
}
