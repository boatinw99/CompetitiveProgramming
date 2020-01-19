#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second
const ll inf = 1e18;
const int N = 55;
int K,mt;
ll x1,y1,x2,y2 ;
ll sz[N];
ll ans =inf ;
pll getcomp(ll x,ll y,int k)
{
    ll len = 1ll<<k ;
    x=((x-1)/len+1)*len;
    y=((y-1)/len+1)*len;
    return {x,y};
}
int findcomp(ll x,ll y,int k)
{
    ll len = 1ll<<(k+1);
    if(x%len==0&&y%len==0)return 4;
    if(x%len!=0&&y%len!=0)return 1;
    if(x%len==0&&y%len!=0)return 3;
    return 2 ;
}
void update(ll &a,ll &b,ll &c,ll &d,int comp,int k,ll a1,ll b1,ll c1,ll d1)
{
    ll cst = sz[k];
    if(comp==1)
    {
        a=min(a,a1);
        b=min(b,b1+cst+1);
        c=min(c,c1+cst+1);
        d=min(d,c+2*cst+1);
        d=min(d,b*2*cst+1);
    }
    else if(comp==2)
    {
        a=min(a,a1+cst+1);
        b=b1;
        d=min(d,d1+cst+1);
        c=min(c,a+2*cst+1);
        c=min(c,d+2*cst+1);
        //printf("aa %d %d\n",comp,k);
    }
    else if(comp==3)
    {
        a=min(a,a1+cst+1);
        d=min(b,d1+cst+1);
        c=c1;
        b=min(b,a+2*cst+1);
        b=min(b,d+2*cst+1);
    }
    else
    {
        b=min(b,b1+cst+1);
        c=min(c,c1+cst+1);
        d=d1;
        a=min(a,c+2*cst+1);
        a=min(a,b+2*cst+1);
    }
}
void solve(pll A,pll B,ll a1,ll b1,ll c1,ll d1,ll a2,ll b2,ll c2,ll d2
        ,int k)
{
    int cc1=findcomp(A.fi,A.se,k),cc2=findcomp(B.fi,B.se,k);
    //printf(" plzz %lld %lld %lld %lld | %lld %lld %lld %lld  \n\n"
       //    ,a1,b1,c1,d1,a2,b2,c2,d2);
    if(k==mt-1)
    {
        ll len = sz[k];
        if(cc1>cc2)
        {
            swap(a1,a2);
            swap(b1,b2);
            swap(c1,c2);
            swap(d1,d2);
            swap(cc1,cc2);
        }
        if(cc1==1)
        {
            if(cc2==2)ans=b1+a2+1;
            else if(cc2==3)ans=c1+a2+1;
            else ans=min(c1+c2+2*len+2,b1+b2+2*len+2);
            //printf("%lld \n",len);
        }
        else if(cc1==2)
        {
            if(cc2==3)
            {
                ans=min(a1+a2+2*len+2,d1+d2+2*len+2);
            }
            else
            {
                ans=d1+b2+1;
            }
        }
        else
        {
            ans=d1+c2+1;
        }
        return ;
    }
    ll ta=inf,tb=inf,tc=inf,td=inf;
    update(ta,tb,tc,td,cc1,k,a1,b1,c1,d1);
    a1=ta,b1=tb,c1=tc,d1=td;
    ///
    ta=inf,tb=inf,tc=inf,td=inf;
    update(ta,tb,tc,td,cc2,k,a2,b2,c2,d2);
    a2=ta,b2=tb,c2=tc,d2=td;
    ///
    A = getcomp(A.fi,A.se,k+1);
    B = getcomp(B.fi,B.se,k+1);
    solve(A,B,a1,b1,c1,d1,a2,b2,c2,d2,k+1);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> K >> x1 >> y1 >> x2 >> y2 ;
    x1++;y1++;x2++;y2++;
    sz[0]=1;
    for(int i=1;i<N;i++)
    {
        sz[i]=(1ll<<i)-1;
    }
    mt = 1 ;
    for(;;mt++)
    {
        pll tmp1=getcomp(x1,y1,mt);
        pll tmp2=getcomp(x2,y2,mt);
        if(tmp1==tmp2)
        {
            break;
        }
    }
    if(mt==1)
    {
        cout << abs(x1-x2)+abs(y1-y2);
        return 0 ;
    }
    ll a1=1,b1=1,c1=1,d1=1,a2=1,b2=1,c2=1,d2=1;
    int cc1=findcomp(x1,y1,0),cc2=findcomp(x2,y2,0);
    if(cc1==1)a1=0,d1=2;
    else if(cc1==2)b1=0,c1=2;
    else if(cc1==3)c1=0,b1=2;
    else d1=0,a1=2;
    if(cc2==1)a2=0,d2=2;
    else if(cc2==2)b2=0,c2=2;
    else if(cc2==3)c2=0,b2=2;
    else d2=0,a2=2;
    pll A=getcomp(x1,y1,1);
    pll B=getcomp(x2,y2,1);
    solve(A,B,a1,b1,c1,d1,a2,b2,c2,d2,1);
    cout << ans ;
    return 0 ;
}
