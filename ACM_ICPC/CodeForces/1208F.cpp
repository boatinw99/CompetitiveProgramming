#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first 
#define se second 
const int N = 1e6+9 , M = 1<<21 , bit = 20 ; 
int arr[N],pw2[bit+1];
pii mx[M];
pii storemx(pii a,pii b)
{
    if(b.fi>a.fi)
    {
        a.se=a.fi,a.fi=b.fi;
        if(b.se>a.se)a.se=b.se;
    }
    else if(b.fi>a.se&&b.fi!=a.fi)a.se=b.fi;
    else if(b.se>a.se)a.se=b.se;
    return a ;
}
bool check(int mask,int idx)
{
    int fd = (mask&arr[idx])^mask;
    return mx[fd].se>idx;
}
int compute(int idx)
{
    int ret = 0 ;
    for(int i=bit;i>=0;i--)///1<<i
    {
        if(check(ret+pw2[i],idx))
        {
            ret+=pw2[i];
        }
    }
    return ret ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ; 
    cin >> n ;
    for(int i=0;i<=bit;i++)pw2[i]=1<<i;
    for(int mask=0;mask<M;mask++)mx[mask]={0,0};
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
        mx[arr[i]]=storemx(mx[arr[i]],{i,0});
    }
    for(int mask=M-1;mask>0;mask--)
    {
        for(int i=0;i<=bit;i++)
        {
            if(mask&pw2[i])
            {
                mx[mask-pw2[i]]=storemx(mx[mask-pw2[i]],mx[mask]);
            }
        }
    }
    int ans = 0 ;x
    for(int i=1;i<=n;i++)
    {
        ans = max(ans,compute(i));
    }
    cout << ans << '\n' ;
    return 0 ;
}