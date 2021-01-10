#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
struct item
{
    ll key,prior;  
    ll val,sum;
    item *l,*r ;
    item(){}
    item(ll key,ll val) : key(key),val(val),prior(rand()),l(NULL),r(NULL) {}
};
typedef item* pitem ;
void upd(pitem t)
{
    t->sum=t->val;
    if(t->l)t->sum+=t->l->sum;
    if(t->r)t->sum+=t->r->sum;
}
void split(pitem t,pitem &l,pitem &r,ll key)
{
    if(!t)
    {
        l=r=NULL;
        return ; 
    }
    else if(t->key<=key)split(t->r,t->r,r,key),l=t;
    else split(t->l,l,t->l,key),r=t ;
    upd(t);
}
void merge(pitem &t,pitem l,pitem r)
{
    if(!l||!r)t=l?l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;    
    else merge(r->l,l,r->l),t=r;
    upd(t);
}
void print(pitem t)
{
    if(!t)return ;
    print(t->l);
    printf("%d ",t->key);
    print(t->r);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,ex=0 ;
    cin >> n ;
    pitem root = NULL ; 
    for(int i=1;i<=n;i++)
    {
        ll x,y ;
        cin >> x >> y ;
        x^=ex,y^=ex ;
        pitem L=NULL,R=NULL;
        split(root,root,R,x);
        ll sum = y ; 
        if(root)sum+=root->sum ;
        cout << x << " " << sum << '\n' ;
        ex = sum ; 
        merge(root,root,new item(x,y));
        merge(root,root,R);
    }
    return 0 ; 
}