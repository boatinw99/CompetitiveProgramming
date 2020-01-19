#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int bi[N];
int a[N];
priority_queue<pair<int,int> > pq;
void update(int in,int co)
{
    for(;in<N;in+=in&-in)bi[in]+=co;
}
int sum(int in)
{
    int x=0;
    for(;in;in-=in&-in)x+=bi[in];
    return x ;
}
main()
{
    int per=0,x,y,i,j,M,type,pos ;
    scanf("%d",&M);
    while(M--)
    {
        scanf("%d",&type);
        if(type==1)
        {
            per++;
            x=per;
            scanf("%d",&pos);
            a[x]=pos;
            update(pos,1);
            pq.push({-pos,x});
        }
        else if(type==2)
        {
            if(pq.empty())
            {
                printf("0\n");
            }
            else
            {
                x=pq.top().first*-1; y=pq.top().second;
                pq.pop();
                printf("%d\n",y);
                update(x,-1);
            }
        }
        else
        {
            scanf("%d",&x);
            printf("%d\n",sum(a[x])-1);
        }
    }
}
