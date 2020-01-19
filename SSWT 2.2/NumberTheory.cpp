#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll pb = 98765431 ;
const int N = 2e5+9 ;
vector<int> V ;
int n,m,a[N],b[N];
ll hasha[N],hashb[N],pbs[N];
bool pi[N];
ll gethash(ll *f,int l,int r)
{
    int len = r-l+1;
    return f[r]-f[l-1]*pbs[len];
}
int query(int i)
{
    int l = i , r = i+m-1;
    int tmp = i ;
    for(int i=0;i<V.size()-1;i++)
    {
        int u = V[i]+1,v=V[i+1]-1;
        int x = tmp+u-1 , y = tmp+v-1;
    //    printf("aa %d %d | %d %d \n",u,v,x,y);
        if(u<=v)
        {
            if(gethash(hashb,u,v)!=gethash(hasha,x,y))
            {
                //printf("%d pls\n",tmp);
                return 0 ;
            }
        }
    }
    return 1 ;
}
int main()
{
    cin >> n >> m ;
    pbs[0]=1;
    for(int i=1;i<N;i++)pbs[i]=pbs[i-1]*pb;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        hasha[i]=hasha[i-1]*pb+a[i];
    }
    V.push_back(0);
    for(int i=1;i<=m;i++)
    {
        cin >> b[i];
        hashb[i]=hashb[i-1]*pb+b[i];
        if(b[i]==1)V.push_back(i);
    }
    V.push_back(m+1);
    int ans = 0 ;
    for(int i=1;i<=n&&i+m-1<=n;i++)
    {
        ans+=query(i);
        //return 0 ;
    }
    cout << ans << '\n' ;
    return 0 ;
}
