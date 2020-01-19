///Not fihished yet because i m too lazy and think that this treap never happen
/// in my life again in o62  ;
#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5+9 ;
struct node
{
    int rnk,sz,val,lazy ;
    struct node *l,*r,*p ;
    node(int val):val(val),rnk(rand()),sz(1),lazy(0),l(NULL),r(NULL),p(NULL){}
};
typedef node *pnode ;
int OLC=0; ///odd-len-cycle;
pnode a[N];
int findsz(pnode t)
{
    return t?t->sz:0;
}
void updsz(pnode t)
{
    if(t)t->sz=findsz(t->l)+findsz(t->r)+1 ;
}
pnode find(pnode t)
{
    while(t->p!=NULL)t=t->p;
    return t;
}
void push(pnode t)
{
    if(!t||!t->lazy)return ;
    swap(t->l,t->r);
    if(t->l)t->l->lazy^=1;
    if(t->r)t->r->lazy^=1;
    t->lazy=0 ;
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
    push(t);
    if(!t)return void(l=r=NULL);
    int cur=findsz(t->l)+add+1 ;
    if(pos<=cur)split(t->l,l,t->l,pos,add),r=t ;
    else split(t->r,t->r,r,pos,cur),l=t ;
    updsz(t);
}
void merge(pnode &t,pnode l,pnode r)
{
    push(l),push(r);
    if(!l||!r)t=l?l:r;
    else if(l->rnk<r->rnk)merge(r->l,l,r->l),t=r;
    else merge(l->r,l->r,r),t=l;
    updsz(t);
}
void add(pnode u,pnode v)
{
    pnode pu=find(u),pv=find(v);
    if(pu->val!=pv->val)
    {

    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,u,v,type ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        a[i]=new node(i);
    }
    while(m--)
    {
        cin >> type >> u >> v ;
        if(type)
        {
            add(a[u],a[v]);
            ///cout << (OLC>0?"no":"yes") << '\n' ;
        }
        else
        {

        }
    }
}
