#include<bits/stdc++.h>
using namespace std ;
struct node
{
    int mxl,mxr,mx,sum,ans,val,rnk,sz,mn;
    node *l,*r ;
    node (){}
    node(int val):sum(val),mx(val),val(val),mxl(max(val,0)),mxr(max(val,0)),ans(max(val,0)),rnk(rand()),sz(1),l(NULL),r(NULL){}
};
typedef node * pnode ;
int findsz(pnode t)
{
    return t?t->sz:0;
}
void updatesz(pnode t)
{
    if(t)t->sz=findsz(t->l)+findsz(t->r)+1;
}
pnode operate(pnode &t,pnode l,pnode r)
{
    if(!l&&r)
    {
        t->mxl=max(0,r->mxl+t->val);
        t->mxr=max(r->mxr,r->sum+t->val);
        t->sum=r->sum+t->val ;
        t->ans=max({t->mxl,t->mxr,r->ans,t->val});
        t->mx=max(t->val,r->mx);
    }
    else if(!r&&l)
    {
        t->mxl=max(l->mxl,l->sum+t->val);
        t->mxr=max(0,l->mxr+t->val);
        t->sum=l->sum+t->val;
        t->ans=max({t->mxl,t->mxr,l->ans,t->val});
        t->mx=max(t->val,l->mx);
    }
    else if(l&&r)
    {
        t->sum=l->sum+r->sum+t->val;
        t->mxl=max(l->mxl,l->sum+max(t->val,t->val+r->mxl));
        t->mxr=max(r->mxr,r->sum+max(t->val,t->val+l->mxr));
        t->ans=max({t->mxl,t->mxr,t->val,l->ans,r->ans,r->mxl+t->val+l->mxr});
        t->mx=max({t->val,l->mx,r->mx});
    }
    else
    {
        t->mxl=t->mxr=t->ans=max(t->val,0);
        t->sum=t->val;
        t->mx=t->val;
    }
    return t ;
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
    if(!t)return void(l=r=NULL);
    int cur = findsz(t->l)+add+1;
    if(cur<=pos)split(t->r,t->r,r,pos,cur),l=t ;
    else split(t->l,l,t->l,pos,add),r=t ;
    updatesz(t);
    t=operate(t,t->l,t->r);
}
void merge(pnode &t,pnode l,pnode r)
{
    if(!l||!r)t=l?l:r;
    else if(l->rnk<r->rnk)merge(r->l,l,r->l),t=r;
    else merge(l->r,l->r,r),t=l ;
    updatesz(t);
    t=operate(t,t->l,t->r);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    pnode root = NULL ;
    int n,x,i,j,m,y ;
    char c ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        merge(root,root,new node(x));
    }
    cin >> m ;
    while(m--)
    {
        cin >> c ;
        if(c=='Q')
        {
            cin >> x >> y ;
            pnode R=NULL,mid=NULL ;
            split(root,root,R,y);
            split(root,root,mid,x-1);
            //printf("aaa %d %d %d\n",mid->ans,mid->mx,mid->sz)
            cout << (mid->ans>0?mid->ans:mid->mx) << '\n' ;
            merge(root,root,mid);
            merge(root,root,R);
        }
        else if(c=='I')
        {
            cin >> x >> y ;
            pnode L=NULL,R=NULL ;
            split(root,root,R,x-1);
            merge(root,root,new node(y));
            merge(root,root,R);
        }
        else if(c=='D')
        {
            cin >> x ;
            pnode L=NULL,R=NULL ;
            split(root,root,R,x);
            split(root,root,L,x-1);
            merge(root,root,R);
        }
        else
        {
            cin >> x >> y ;
            pnode L=NULL,R=NULL ;
            split(root,root,R,x);
            split(root,root,L,x-1);
            merge(root,root,new node(y));
            merge(root,root,R);
        }
    }
}
