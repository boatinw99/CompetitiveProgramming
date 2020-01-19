#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9;
int a[N];
struct jet
{
    int maxans,lmax1,rmax1;
};
jet findans(int n,int all)
{
    int i,sum=0;
    int max1=0,lmax=0,rmax=0,l=1,r=1;
    jet J ;
    for(i=1;i<=n;i++)
    {
        sum+=a[i];
        if(sum>max1)
        {
            max1=sum; lmax=l; rmax=r;
        }
        if(sum==max1)
        {
            if(r-l+1<rmax-lmax+1)
            {
                max1=sum; lmax=l; rmax=r;
            }
        }
        r++;
        if(sum<=0)
        {
            l=i+1; r=i+1;
            sum=0;
        }
    }
    J.maxans=max1+all;
    J.lmax1=lmax;
    J.rmax1=rmax;
    return J ;
}
main()
{
    int n,i,j;
    char c;
    jet J1,J2 ;
    int suml=0,sumr=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf(" %c %d",&c,&a[i]);
        if(c=='R')sumr+=a[i],a[i]*=-1;
        else suml+=a[i];
    }
    if(sumr==0)
    {
        printf("R %d 1 %d",suml,n);
        return 0;
    }
    if(suml==0)
    {
        printf("L %d 1 %d",sumr,n);
        return 0;
    }
    J1=findans(n,sumr);
    for(i=1;i<=n;i++)a[i]*=-1;
    J2=findans(n,suml);
    if(J1.maxans>=J2.maxans)
    {
        printf("R ");
        printf("%d %d %d",J1.maxans,J1.lmax1,J1.rmax1);
    }
    else if(J2.maxans>J1.maxans)
    {
        printf("L ");
        printf("%d %d %d",J2.maxans,J2.lmax1,J2.rmax1);
    }
}
