#include<bits/stdc++.h>
using namespace std ;
struct node
{
    int rnk,sz,lazy,val ;
    node *l,*r;
    node(int val):val(val),rnk(rand()),lazy(0),sz(1),l(NULL),r(NULL){}
};
typedef node * pnode ;
int findsz(pnode t)
{
    return t?t->sz:0;
}
void updsz(pnode t)
{
    if(t)t->sz=findsz(t->l)+findsz(t->r)+1;
}
void lazy(pnode t)
{
    if(!t||!t->lazy)return ;
    t->val+=t->lazy;
    if(t->l)t->l->lazy+=t->lazy;
    if(t->r)t->r->lazy+=t->lazy;
    t->lazy=0 ;
}
void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t)return void(l=r=NULL);
    lazy(t);
    if(t->val<=key)split(t->r,t->r,r,key),l=t;
    else split(t->l,l,t->l,key),r=t;
}
void merge(pnode &t,pnode l,pnode r)
{
    lazy(l);
    lazy(r);
    if(!l||!r)t=l?l:r;
    else if(l->rnk<r->rnk)merge(r->l,l,r->l),t=r;
    else merge(l->r,l->r,r),t=l ;
}
bool find(pnode t,int key)
{
    if(!t)return 0;
    lazy(t);
    if(t->val==key)return 1 ;
    else if(t->val>key)return find(t->l,key);
    else return find(t->r,key);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,m,u,v,x,type,A,B,C ;
    pnode root = NULL ;
    cin >> n >> m;
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        merge(root,root,new node(x));
    }
    while(m--)
    {
        cin >> type ;
        if(type==1)
        {
            cin >> x ;
            cout << find(root,x) << '\n';
        }
        else
        {
            cin >> A >> B >> C ;
            if(find(root,A))
            {
                pnode tmp=NULL ;
                split(root,tmp,root,A-1);
                if(tmp)tmp->lazy+=B;
                if(root)root->lazy+=C;
                merge(root,root,tmp);
            }
        }
    }
}
