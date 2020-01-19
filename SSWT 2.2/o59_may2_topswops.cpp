#include<bits/stdc++.h>
using namespace std ;
struct node
{
    int val,rnk,sz,lazy ;
    node *l,*r;
    node(int val):val(val),rnk(rand()),sz(1),lazy(0),l(NULL),r(NULL){}
};
typedef node *pnode ;
int findsz(pnode t)
{
    return t?t->sz:0 ;
}
void updsz(pnode t)
{
    if(t)t->sz=findsz(t->l)+findsz(t->r)+1 ;
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
    int cur = findsz(t->l)+add+1;
    if(cur<=pos)split(t->r,t->r,r,pos,cur),l=t;
    else split(t->l,l,t->l,pos,add),r=t ;
    updsz(t);
}
void merge(pnode &t,pnode l,pnode r)
{
    push(l),push(r);
    if(!l||!r)t=l?l:r;
    else if(l->rnk>r->rnk)merge(l->r,l->r,r),t=l ;
    else merge(r->l,l,r->l),t=r;
    updsz(t);
}
int find(pnode t)
{
    push(t);
    int ret=t->val;
    if(t->l)ret=find(t->l);
    updsz(t);
    return ret ;
}
void print(pnode t)
{
    if(!t)return ;
    push(t);
    if(t->l)
    {
        cout << "L";
        print(t->l);
    }
    cout << t->val ;
    if(t->r)
    {
        cout << "R" ;
        print(t->r);
    }
    updsz(t);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,x,ans=0 ;
    pnode root = NULL ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        merge(root,root,new node(x));
    }
    while(1)
    {
        int x = find(root) ;
        if(x==1)break;
        pnode tmp = NULL;
        split(root,root,tmp,x);
        root->lazy^=1;
        merge(root,root,tmp);
        ans++;
    }
    cout << ans ;
}
