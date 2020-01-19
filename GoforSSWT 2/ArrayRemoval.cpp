#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
typedef long long ll;
int a[N];
int par[N];
int rank1[N];
ll value[N],max1=0;
bool b[N];
stack<ll> st,ans;
int findparent(int i)
{
    if(par[par[i]]!=i)
    {
        par[i]=findparent(par[i]);
    }
    return par[i];
}
void unionset(int par1,int par2)
{
    if(rank1[par1]>=rank1[par2])
    {
        rank1[par1]+=rank1[par2];
        value[par1]+=value[par2];
        max1=max(max1,value[par1]);
        par[par2]=par1;
    }
    else
    {
        rank1[par2]+=rank1[par1];
        value[par2]+=value[par1];
        max1=max(max1,value[par2]);
        par[par1]=par2;
    }
}
main()
{
    int n,i,j,x ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        value[i]=a[i];
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        st.push(x);
        par[i]=i;
        rank1[i]=1;
    }
    int par1,par2;
    while(!st.empty())
    {
        x=st.top(); st.pop();
        par1=0; par2=0;
        b[x]++;
        if(b[x-1]==1)par1=findparent(x-1);
        if(b[x+1]==1)par2=findparent(x+1);
        if(par1!=0&&par2!=0)
        {
            unionset(par1,x);
            unionset(par1,par2);
        }
        else if(par1==0&&par2!=0)
        {
            unionset(x,par2);
        }
        else if(par1!=0&&par2==0)
        {
            unionset(par1,x);
        }
        else max1=max(max1,value[x]);
        ans.push(max1);
    }
    while(!ans.empty())
    {
        printf("%lld\n",ans.top());
        ans.pop();
    }
}
