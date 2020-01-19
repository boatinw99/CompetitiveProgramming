#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int a[N];
int bi[N];
void update(int i)
{
    for(;i<=N-4;i+=i&-i)bi[i]++;
}
int getsum(int i)
{
    int x=0;
    for(;i>0;i-=i&-i)x+=bi[i];
    return x;
}
main()
{
    int n,x,max1=1,i,j ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=n;i>0;i--)
    {
        update(a[i]);
        x=getsum(a[i]);
        x++;
        if(x>n-i+1)
        {
            x--;
        }
        max1=max(max1,x);
    }
    printf("%d",max1);
}
