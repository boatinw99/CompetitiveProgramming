#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5+9;
int a[N];
int ans=0,n;
vector<pair<int,int> > v;
vector<pair<int,int> > ::iterator it ;
bool b[N];
bool tram[N];
char s[N];
void bfs(int i)
{
    ans++;
    b[i]++;
    if(a[i-1]>=a[i]&&b[i-1]==0)bfs(i-1);
    if(a[i+1]>=a[i]&&b[i+1]==0)bfs(i+1);
}
int findans(int k)
{
    int i,l=k,r=k,d ;
    while(a[r+1]==a[k])
    {
        r++;
        b[r]++;
    }
    while(a[l-1]==a[k])
    {
        l--;
        b[l]++;
    }
    d=r-l+1;
    for(i=l-1;a[i]<=a[i+1]&&i>=1;i--)
    {
        b[i]++;
        d=r-i+1;
    }
    for(i=r+1;a[i-1]>=a[i]&i<=n;i++)
    {
        b[i]++;
        d=max(d,i-l+1);
    }
    return d;
}
main()
{
    int k,i,j,l,r ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%s",&s);
    for(i=0;i<n;i++)
    {
        if(s[i]=='T')tram[i+1]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(tram[i]==1&&b[i]==0)
        {
            bfs(i);
        }
    }
    int pr=0;
    if(b[k]==1)
    {
        //printf("aaa %d\n",ans);
        for(i=1;i<=n;i++)
        {
            if(b[i]==0)v.push_back({a[i],i});
        }
        sort(v.begin(),v.end(),greater<pair<int,int> >());
        for(it=v.begin();it!=v.end();it++)
        {
            if(b[it->second]==0)
            {
                pr=max(pr,findans(it->second));
            }
        }
        printf("%d",ans+pr);
        return 0 ;
    }
    printf("%d",findans(k));
}
