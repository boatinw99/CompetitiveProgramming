#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ;
struct node
{
    int rnk,sz=0;
    ll lazy=0,sum=0,mx,val,ai,ans=0 ;
    node *l,*r;
    node(ll x,ll val,ll mx)
    :ai(x),val(val),rnk(rand()),l(NULL),r(NULL),mx(mx){}
};
typedef node* pnode ;
int findsz(pnode t)
{
    return t?t->sz:0;
}
void push(pnode t)
{
    if(!t||(!t->lazy))return ;
    t->mx+=t->lazy;
    t->ans+=t->lazy;
    if(t->l)t->l->lazy+=t->lazy;
    if(t->r)t->r->lazy+=t->lazy;
    t->lazy=0;
}
void update(pnode t)
{
    if(!t)return ;
    t->sum=t->ai;
    t->ans=t->mx;
    if(t->l)
    {
        push(t->l);
        t->ans=max(t->l->ans,t->ans);
        t->sum+=t->l->sum;
    }
    if(t->r)
    {
        push(t->r);
        t->ans=max(t->r->ans,t->ans);
        t->sum+=t->r->sum;
    }
}
void split(pnode t,pnode &l,pnode &r,ll key)
{
    push(t);
    if(!t)l=r=NULL;
    else if(t->val<=key)split(t->l,l,t->l,key),r=t;
    else split(t->r,t->r,r,key),l=t;
    update(t);
}
void merge(pnode &t,pnode l,pnode r)
{
    push(l),push(r);
    if(!l||!r)t=l?l:r;
    else if(l->rnk<r->rnk)merge(r->l,l,r->l),t=r;
    else merge(l->r,l->r,r),t=l;
    update(t);
}
int print(pnode t)
{
    if(!t)return 0;
    if(t->l)
    {
        printf("L=(%lld -> %lld)\n",t->val,t->l->val);
        int ret = print(t->l);
    }
    if(t->r)
    {
        printf("R = (%lld -> %lld) \n",t->val,t->r->val);
        int ret = print(t->r);
    }
    //printf("remain %lld \n",t->val);
    return 0 ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll ans = 0 ;
    int n,T,ret=0;
    ll u,v ;
    ll m1,m2 ;
    pnode root = NULL ;
    cin >> n >> T >> m1 >> m2 ;
    for(int i=1;i<=n;i++)
    {
        cin >> u >> v ;
        if(T==2)
        {
            u=u+(ans%m1);
            v=v+(ans%m2);
        }
        pnode R=NULL;
        split(root,root,R,v);
        ll add = 0 ;
        if(root!=NULL)add=root->sum ;
        merge(root,root,new node(u,v,u+add+v));
        //print(R);
        if(R)R->lazy+=u;
        //if(R)printf("wtf %lld %lld\n\n",R->ans,R->lazy);
        merge(root,root,R);
        ans = root->ans ;
        cout << ans << '\n' ;
    }
}
