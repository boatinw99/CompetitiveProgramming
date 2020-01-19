#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int pre[N],post[N];
int in[N],a[N],pr=0;
int max1;
bool b[N];
queue<int> q ;
void dfs(int i,int pre1,int pro1,int pre2,int pro2)
{
    int j=a[i];
    b[i]++;
    if(b[j]==0)
    {
        pre1+=post[i];
        pro1+=pre[i];
        swap(pro1,pre1);
        pro1=max(pro1,pre1);

        pre2+=post[i];
        pro2+=pre[i];
        swap(pro2,pre2);
        pro2=max(pro2,pre2);

        dfs(j,pre1,pro1,pre2,pro2);
    }
    else
    {
        max1=max(pre1,pre2);
        max1=max(max1,pro2);
    }
}
main()
{
    int m,n,i,j,x ;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&n);
        pr=0;
        for(i=1;i<=n;i++)
        {
            pre[i]=0;
            post[i]=1;
            in[i]=0;
            b[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            in[a[i]]++;
        }
        for(i=1;i<=n;i++)
        {
            if(in[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            i=q.front(); q.pop();
            b[i]++;
            post[i]=max(post[i],pre[i]);
            j=a[i];
            pre[j]+=post[i];
            post[j]+=pre[i];
            in[j]--;
            if(in[j]==0)q.push(j);
        }
        for(i=1;i<=n;i++)post[i]=max(post[i],pre[i]);
        for(i=1;i<=n;i++)
        {
            if(b[i]==0)
            {
                max1=0;
                j=a[i];
                dfs(j,pre[i],post[i],pre[i],pre[i]);
                pr+=max1;
            }
        }
        printf("%d\n",n-pr);
    }
}
