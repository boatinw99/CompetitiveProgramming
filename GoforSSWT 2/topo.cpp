#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
queue<int> q,ans ;
vector<int>path[N];
vector<int>::iterator it;
int dag[N];
main()
{
    int n,m,i,j,x,u,v ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        dag[v]++;
    }
    for(i=1;i<=n;i++)
    {
        if(dag[i]==0)
        {
            q.push(i);
            ans.push(i);
        }
    }
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(it=path[x].begin();it!=path[x].end();it++)
        {
            dag[*it]--;
            if(dag[*it]==0)q.push(*it),ans.push(*it);
        }
    }
    if(ans.size()==n)
    {
        while(!ans.empty())
        {
            printf("%d\n",ans.front());
            ans.pop();
        }
    }
    else printf("no");
}
