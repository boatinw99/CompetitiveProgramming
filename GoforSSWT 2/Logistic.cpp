#include<bits/stdc++.h>
using namespace std ;
const int N = 109;
int dp[N][N][2];
vector<pair<int,int> > v[N];
vector<pair<int,int> >::iterator it;
priority_queue<pair<int,pair<int,pair<int,int> > > > pq;
//4 paremeters
int a[N];
main()
{
    int n,m,i,j,s,t,f,l,r,val,x,y ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d %d %d",&s,&t,&f);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&val);
        v[l].push_back({r,val});
        v[r].push_back({l,val});
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=f;j++)
        {
            dp[i][j][0]=1e9;
            dp[i][j][1]=1e9;
        }
    }
    ///0->non-used a card
    ///1->used a card
    //// 4 parameters -> prize,town,fuel,used or non-used
    dp[s][0][0]=0;
    pq.push({0,{s,{0,0}}});
    int prize,town,fuel,uon,co=0 ;
    while(!pq.empty())
    {
        prize=pq.top().first*-1;
        town=pq.top().second.first;
        fuel=pq.top().second.second.first;
        uon=pq.top().second.second.second;
        pq.pop();
        if(prize!=dp[town][fuel][uon])continue;
        if(uon==0)
        {
            for(j=fuel+1;j<=f;j++)
            {
                if(prize+a[town]*(j-fuel)<dp[town][j][0])
                {
                    dp[town][j][0]=prize+a[town]*(j-fuel);
                    pq.push({-dp[town][j][0],{town,{j,0}}});
                }
                if(prize<dp[town][j][1])
                {
                    dp[town][j][1]=prize;
                    pq.push({-prize,{town,{j,1}}});
                }
            }
        }
        else
        {
            for(j=fuel+1;j<=f;j++)
            {
                if(prize+a[town]*(j-fuel)<dp[town][j][1])
                {
                    dp[town][j][1]=prize+a[town]*(j-fuel) ;
                    pq.push({-dp[town][j][1],{town,{j,1}}});
                }
            }
        }
        for(it=v[town].begin();it!=v[town].end();it++)
        {
            if(fuel>=it->second&&prize<dp[it->first][fuel-it->second][uon])
            {
                dp[it->first][fuel-it->second][uon]=prize;
                pq.push({-dp[it->first][fuel-it->second][uon],
                        {it->first,{fuel-it->second,uon}}});
            }
        }
    }
    printf("%d",dp[t][f][1]);
}
