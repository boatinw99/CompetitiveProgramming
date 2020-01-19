#include<bits/stdc++.h>
using namespace std ;
struct node
{
    int val,rnk,sz ;
    node *l,*r ;
    node(){}
    node(int val):val(val),rnk(rand()),sz(1),l(NULL),r(NULL){};
};
typedef node * pnode ;
int fdsz(pnode t)
{
    return t?t->sz:0;
}
void updsz(pnode t)
{
    if(t)t->sz=fdsz(t->l)+fdsz(t->r)+1;
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
    if(!t)return void(l=r=NULL);
    int cur = add+fdsz(t->l)+1;
    if(cur<=pos)split(t->r,t->r,r,pos,cur),l=t;
    else split(t->l,l,t->l,pos,add),r=t;
    updsz(t);
}
void merge(pnode &t,pnode l,pnode r)
{
    if(!l||!r)t=l?l:r;
    else if(l->rnk<r->rnk)merge(r->l,l,r->l),t=r;
    else merge(l->r,l->r,r),t=l;
    updsz(t);
}
int find(pnode t,int pos,int add=0)
{
    if(!t)return -1 ;
    int cur = add+fdsz(t->l)+1;
    if(cur==pos)return t->val ;
    else if(cur<pos)return find(t->r,pos,cur);
    else return find(t->l,pos,add);
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,i,j,x,type,A,B,len,u,v ;
    pnode root = NULL ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        merge(root,root,new node(x));
    }
    while(m--)
    {
        cin >> type ;
        if(type==2)
        {
            cin >> x ;
            cout << find(root,x) << '\n' ;
        }
        else
        {
            cin >> A >> len >> B ;
            u=A,v=A+len-1;
            if(v<B)
            {
                pnode L,R1,R2 ;
                split(root,root,R2,B-1);
                split(root,root,R1,v);
                split(root,L,root,u-1);
                merge(L,L,R1);
                merge(root,L,root);
                merge(root,root,R2);
            }
            else
            {
                pnode L=NULL,R1=NULL,R2=NULL;
                split(root,root,R2,v);
                split(root,L,root,u-1);
                split(L,L,R1,B-1);
                merge(root,L,root);
                merge(R1,R1,R2);
                merge(root,root,R1);
            }
        }
    }
    /*
    if( a > b ){
				split( t, t, r2, a+L-1 );
				split( t, t, r, a-1 );
				split( t, t, l, b-1 );
				merge( t, t, r );
				merge( t, t, l );
				merge( t, t, r2 );

			} else{
				split( t, t, r2, b-1 );
				split( t, t, r, a+L-1 );
				split( t, t, l, a-1 );
				merge( t, t, r );
				merge( t, t, l );
				merge( t, t, r2 );
			}
    */
}
