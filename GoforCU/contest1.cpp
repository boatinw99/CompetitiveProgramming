#include<bits/stdc++.h>
using namespace std ;
vector<int>v[100009];
vector<int>::iterator it,it1;
map<int,int> m;
map<int,int> ::iterator itm;
int a[100009];
main()
{
    int n,q,x,i,j,l,r ;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    i=1 ;
    for(itm=m.begin();itm!=m.end();itm++,i++)itm->second=i;
    for(i=1;i<=n;i++)
    {
        x=m[a[i]];
        v[x].push_back(i);
        printf("%d ",x);
    }
    printf("\n");
    while(q--)
    {
        scanf("%d %d %d",&l,&r,&x);
        x=m[x];
        it=lower_bound(v[x].begin(),v[x].end(),l);
        it1=upper_bound(v[x].begin(),v[x].end(),r);
        printf("%d\n",it1-it);
    }
}
