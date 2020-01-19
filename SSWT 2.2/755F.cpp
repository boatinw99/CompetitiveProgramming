#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9 ;
bitset<N> bs ;
int cnt[N],a[N],cst[N],arr[N],sz2=0,arr2[N],sz=0;
bool vst[N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k,i,j ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)cin >> a[i] ;
    for(i=1;i<=n;i++)
    {
        if(!vst[i])
        {
            vst[i]++;
            int len=1,x=i ;
            while(!vst[a[x]])x=a[x],len++,vst[x]++;
            arr2[sz++]=len ;
            cnt[len]++;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(cnt[i])
        {
            int val=cnt[i];
            for(j=0;(1<<j)<=val;val-=(1<<j),j++)arr[sz2++]=(1<<j)*i ;
            if(val)arr[sz2++]=val*i ;
        }
    }
    bs.set(0);
    for(i=0;i<sz2;i++)bs|=bs<<arr[i];
    cout << (bs.test(k)?k:k+1) << " " ;
    memset(vst,0,sizeof vst);
    int ans = 0 ,rmn = n;
    for(i=0;i<sz;i++)
    {
        if(k*2>=arr2[i])
        {
            k-=arr2[i]/2;
            ans+=arr2[i]-(arr2[i]&1);
            arr2[i]&=1;
        }
        else
        {
            ans+=k*2;
            k=0 ;
        }
    }
    for(i=0;i<sz&&k;i++)if(arr2[i])k--,ans++;
    cout << ans ;
}
