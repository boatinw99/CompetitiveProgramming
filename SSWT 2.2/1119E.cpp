#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 3e5+9 ;
ll cnt1=0,cnt2=0,ans=0,x,tmp=0;
void compute()
{
    printf("comp %lld %lld %lld | x = %lld \n",cnt1,cnt2,ans,x);
    if(cnt1*2>=x)
    {
        cnt1-=x/2 ;
        ans+=x/2 ;
        cnt2+=(x/2)*2 ;
        cnt1+=x&1 ;
        x=0;
    }
    else
    {
        ans+=cnt1 ;
        ///
        cnt2+=cnt1*2 ;
        ///
        //tmp = cnt1*2;
        x-=cnt1*2 ;
        cnt1=0 ;
    }
    printf("after comp %lld %lld %lld | x = %lld \n",cnt1,cnt2,ans,x);
}
main()
{
    int n,i,j;
    cin >> n ;
    while(n--)
    {
        cin >> x ;
        compute();
        if((cnt2*3)/2<=x/2*2&&x>1)
        {
            cnt1+=cnt2*3/2;
            ans-=cnt2/2;
            cnt2=0;
            compute();
        }
        else if(x>1)
        {

            ll ret = x-(x&1)>>1;
            ll tmp1 = (ret-1)*2/3+1 ;
            cnt2-=tmp1*2 ;
            cnt1+=tmp1*3;
            ans-=tmp1;
            compute();
        }
        if(x>=1)
        {
            ans+=x/3 ;
            cnt2+=(x/3)*2 ;
            x-=(x/3)*3;
            cnt1+=x%3;
        }
        cout << '\n' ;
    }
    cout << ans ;
}
