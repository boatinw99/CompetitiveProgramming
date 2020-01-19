#include<bits/stdc++.h>
using namespace std ;
struct node
{
    int rnk,sz,lzy;
    char c ;
    node *l,*r ;
    node() { }
	node(char c):c(c),lzy(0),rnk(rand()),sz(1),l(NULL),r(NULL){};
};
typedef node * pnode ;
string s;
int findsz(pnode t)
{
    return t?t->sz:0 ;
}
void updsz(pnode t)
{
    if(t)t->sz=findsz(t->l)+findsz(t->r)+1;
}
void lazy(pnode t)
{
    if(!t||!t->lzy)return ;
    swap(t->l,t->r);
    if(t->l)t->l->lzy^=1;
    if(t->r)t->r->lzy^=1;
    t->lzy=0;
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
    lazy(t);
    if(!t)return void(l=r=NULL);
    int cur=add+findsz(t->l)+1;
    if(cur<=pos)split(t->r,t->r,r,pos,cur),l=t ;
    else split(t->l,l,t->l,pos,add),r=t ;
    updsz(t);
}
void merge(pnode &t,pnode l,pnode r)
{
    lazy(l),lazy(r);
    if(!l||!r)t=l?l:r ;
    else if(l->rnk>r->rnk)merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r ;
    updsz(t);
}
void print(pnode t)
{
    lazy(t);
    if(!t)return ;
    print(t->l);
    cout << t->c ;
    print(t->r);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> s ;
    int m=s.size(),n,i,j,x,y ;
    char type ;
    pnode root=NULL ;
    for(i=0;i<m;i++)merge(root,root,new node(s[i]));
    cin >> m ;
    while(m--)
    {
        cin >> type >> x ;
        if(type=='I')
        {
            cin >> s ;
            n=s.size();
            pnode tmp ;
            split(root,root,tmp,x);
            for(i=0;i<n;i++)merge(root,root,new node(s[i]));
            merge(root,root,tmp);
        }
        else
        {
            cin >> y ;
            pnode L,R ;
            split(root,root,R,y);
            split(root,L,root,x-1);
            root->lzy^=1;
            merge(root,L,root);
            merge(root,root,R);
        }
    }
    print(root);
}
