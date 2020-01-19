#include<bits/stdc++.h>
using namespace std ;
const int N = 20009;
const int M = 200009;
int a[N];
int bi[M*2+N];
int ans[M],n;
pair<int,int> query[M];
vector<pair<int,int> >  v;
vector<pair<int,int> >::iterator it;
vector<int>key;
vector<int>::iterator itkey;
int keysize ;
void update(int in)
{
    for(;in<=keysize;in+=in&-in)bi[in]++;
}
int getsum(int in)
{
    int x=0;
    for(;in>0;in-=in&-in)x+=bi[in];
    return x;
}
main()
{
    int n,q,i,j,A,B,S,E ;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        key.push_back(a[i]);
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d %d %d %d",&A,&B,&S,&E);
        query[i]={S,E};
        key.push_back(S);
        key.push_back(E);
        if(A>1)
        v.push_back({A-1,i}) ;
        v.push_back({B,i});
    }
    i=1;
    sort(key.begin(),key.end());
    keysize=key.size();
    sort(v.begin(),v.end());
    it=v.begin();
    int sumx,sumy;
    for(i=1;i<=n;i++)
    {
        itkey=lower_bound(key.begin(),key.end(),a[i]);
        update(itkey-key.begin()+1);
        while(it->first==i&&it!=v.end())
        {
            itkey=lower_bound(key.begin(),key.end(),
                    query[it->second].first);
                    itkey--;
            sumx=getsum(itkey-key.begin()+1);
            itkey=lower_bound(key.begin(),key.end(),
                    query[it->second].second);
            sumy=getsum(itkey-key.begin()+1);
            if(ans[it->second]==0)
            {
                ans[it->second]=(sumy-sumx)*-1;
            }
            else ans[it->second]+=sumy-sumx;
            it++;
        }
    }
    for(i=1;i<=q;i++)
    {
        printf("%d ",(ans[i]<0)?ans[i]*-1:ans[i]);
    }
}
