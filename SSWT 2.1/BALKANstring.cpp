#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll pb = 98765431 ;
const int N = 2e5+9 ;
ll pi[N];
struct node
{
    int rnk,sz,lazy;
    char c ;
    ll h1,h2 ;
    node *l,*r ;
    node(){}
    node(char c):rnk(rand()),sz(1),c(c),h1(0),h2(0),l(NULL),r(NULL),lazy(0){};
};
typedef node *pnode ;
int findsz(pnode t)
{
    return t?t->sz:0;
}
void updatesz(pnode t)
{
    if(t)t->sz=findsz(t->l)+findsz(t->r)+1;
}
void lazy(pnode t)
{
    if(!t||!t->lazy)return ;
    swap(t->l,t->r);
    if(t->l)t->l->lazy^=1,swap(t->l->h1,t->l->h2);
    if(t->r)t->r->lazy^=1,swap(t->r->h1,t->r->h2);
    t->lazy=0;
}
void operate(pnode &t)
{
    if(t->r&&!t->l)
    {
        t->h1=(t->c-'a')*pi[t->r->sz]+t->r->h1;
        t->h2=(t->c-'a')+t->r->h2*pb;
    }
    else if(!t->r&&t->l)
    {
        t->h1=(t->c-'a')+t->l->h1*pb;
        t->h2=(t->c-'a')*pi[t->l->sz]+t->l->h2;
    }
    else if(t->l&&t->r)
    {
        t->h1=t->l->h1*pi[t->r->sz+1]+(t->c-'a')*pi[t->r->sz]+t->r->h1;
        t->h2=t->r->h2*pi[t->l->sz+1]+(t->c-'a')*pi[t->l->sz]+t->l->h2;
    }
    else if(t)
    {
        t->h1=t->c-'a';
        t->h2=t->c-'a';
    }

}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
    lazy(t);
    if(!t)return void(l=r=NULL);
    int cur = add+findsz(t->l)+1;
    if(cur<=pos)split(t->r,t->r,r,pos,cur),l=t;
    else split(t->l,l,t->l,pos,add),r=t;
    updatesz(t);
    operate(t);
}
void merge(pnode &t,pnode l,pnode r)
{
    lazy(l),lazy(r);
    if(!l||!r)t=l?l:r;
    else if(l->rnk<r->rnk)merge(r->l,l,r->l),t=r;
    else merge(l->r,l->r,r),t=l;
    updatesz(t);
    operate(t);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,type,x,y,k ;
    char d ;
    pnode root = NULL ;
    cin >> n >> m ;
    pi[0]=1;
    for(i=1;i<=n;i++)pi[i]=pi[i-1]*pb;
    for(i=1;i<=n;i++)
    {
        cin >> d ;
        merge(root,root,new node(d));
    }
    for(i=1;i<=m;i++)
    {
        cin >> d ;
        if(d=='Q')
        {
            cin >> x >> y ;
            pnode L,R ;
            split(root,root,R,y);
            split(root,L,root,x-1);
            cout << (root->h1==root->h2?"YES":"NO") << '\n' ;
            merge(root,root,R);
            merge(root,L,root);
        }
        else if(d=='M')
        {
            cin >> type ;
            if(type==1)
            {
                cin >> x >> y >> k ;
                pnode L,R,MID ;
                split(root,root,R,y);
                split(root,L,root,x-1);
                merge(L,L,R);
                split(L,L,R,k);
                merge(root,L,root);
                merge(root,root,R);
            }
            else if(type==2)
            {
                cin >> x >> y ;
                pnode L,R ;
                split(root,root,R,y);
                split(root,L,root,x-1);
                root->lazy^=1;
                swap(root->h1,root->h2);
                merge(root,root,R);
                merge(root,L,root);
            }
            else
            {
                cin >> x >> d ;
                pnode L,R ;
                split(root,root,R,x-1);
                merge(root,root,new node(d));
                merge(root,root,R);
            }
        }
    }
}
