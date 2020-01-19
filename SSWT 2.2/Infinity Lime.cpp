#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 7e5+9 ,inf = 2e9+7;
int a[N],ans[N],n;
pii query[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m ;
    cin >> n >> m ;
    for(int i=1;i<=n;i++)cin >> a[i] ;
    sort(a+1,a+1+n);
    for(int i=1;i<=m;i++)
    {
        int x ;
        cin >> x ;
        query[i]={x,i};
    }
    sort(query+1,query+1+m);
    int r=1,excnt=0;
    a[n+1]=inf ;
    for(int i=0;i<=n;i++)
    {
        int len = a[i+1]-a[i]-1;
        while(excnt+len>=query[r].fi&&r<=m)
        {
            int tmp = query[r].fi-excnt;
            ans[query[r].se] = tmp+a[i] ;
            //printf("aa %d->%d |%d %d | %d %d\n",r,i,tmp,a[i],excnt,len);
            r++;
        }
        excnt+=len;
    }
    for(int i=1;i<=m;i++)cout << ans[i] << " " ;
    return 0 ;
}
