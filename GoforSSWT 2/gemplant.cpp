#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9;
int bi[N];
void update(int i,int j)
{
    for(;i<N;i+=i&-i)bi[i]+=j;
}
int findsum(int i)
{
    int sum=0;
    for(;i;i-=i&-i)sum+=bi[i];
    return sum ;
}
main()
{
    int n,m,T,l,r ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d %d",&T,&l,&r);
        if(T==1)
        {
            update(r,l);
        }
        else
        {
            printf("%d\n",findsum(r)-findsum(l-1));
        }
    }
}
