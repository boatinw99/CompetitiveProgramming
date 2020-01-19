#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9;
typedef long long ll ;
int n,l;
bool upordown[N];
int pos[N];
ll findans(int a)
{
    int i;
    ll ans=0 ;
    if(a==0)
    {
        for(i=0;i<n;i++)
        {
            if(pos[i]==1&&upordown[i]==0);
            else if(pos[i]==l&&upordown[i]==1);
            else
            {
                if(upordown[i]==0)ans+=l-pos[i]+1;
                else ans+=pos[i]+1;
            }
        }
        return ans;
    }
    for(i=0;i<n;i++)
    {
        if(upordown[i]==0)
        {
            if(a<=pos[i])
            {
                ans+=a-pos[i]+l+1;
            }
            else ans+=a-pos[i]+1;
        }
        else
        {
            if(a<=pos[i])
            {
                ans+=pos[i]-a+1;
            }
            else ans+=l-(a-pos[i])+1;
        }
        //printf("aa %d\n",ans);
    }
    return ans;
}
void update(int a,int b)
{
    pos[a]+=b;
    if(pos[a]>l)pos[a]-=l;
}
void flip(int a)
{
    if(upordown[a]==0)
    {
        pos[a]-=2;
        if(pos[a]<=0)pos[a]+=l;
        upordown[a]=1;
    }
    else
    {
        pos[a]+=2;
        if(pos[a]>l)pos[a]-=l;
        upordown[a]=0;
    }
}
main()
{
    int q,a,b,i,j;
    char c;
    scanf("%d %d %d",&n,&l,&q);
    for(i=0;i<n;i++)
    {
        pos[i]=1;
    }
    while(q--)
    {
        scanf(" %c",&c);
        if(c=='s')
        {
            scanf("%d %d",&a,&b);
            update(a,b);
        }
        else
        {
            scanf("%d",&a);
            if(c=='f')
            {
                flip(a);
            }
            if(c=='q')
            {
                printf("%lld\n",findans(a));
            }
        }
    }
}
