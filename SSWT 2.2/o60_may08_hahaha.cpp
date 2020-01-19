#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int inf = 1e9 ;
struct node
{
    int val,rnk,sz,cnt[5]={0,0,0,0,0},lazy,rev ;
    ll inv ;
    node *l,*r ;
    node(int val):val(val),rnk(rand()),sz(1),inv(0),l(NULL),r(NULL),lazy(inf),rev(0){}
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
    if(!t)return ;
    if(t->rev)
    {
        swap(t->l,t->r);
        ll tmp = t->inv ;
        t->inv=1ll*t->sz*(t->sz-1)/2-tmp ;
        for(int i=0;i<5;i++)t->inv-=1ll*t->cnt[i]*(t->cnt[i]-1)/2 ;
        if(t->l)t->l->rev^=1;
        if(t->r)t->r->rev^=1;
        t->rev=0 ;
    }
    if(t->lazy!=inf)
    {
        t->val=t->lazy ;
        t->inv=0 ;
        for(int i=0;i<5;i++)t->cnt[i]=0 ;
        t->cnt[t->val]=t->sz ;
        if(t->l)t->l->lazy=t->lazy;
        if(t->r)t->r->lazy=t->lazy;
        t->lazy=inf ;
    }
}
void update(pnode t)
{
    if(!t)return ;
    t->inv = 0 ;
    memset(t->cnt,0,sizeof t->cnt);
    t->cnt[t->val]=1;
    if(t->l&&t->r)
    {
        for(int i=4;i>=0;i--)for(int j=i-1;j>=0;j--)
            t->inv+=1ll*t->l->cnt[i]*t->r->cnt[j];
    }
    if(t->l)
    {
        for(int i=t->val+1;i<5;i++)
            t->inv+=t->l->cnt[i];
        for(int i=0;i<5;i++)t->cnt[i]+=t->l->cnt[i];
        t->inv+=t->l->inv ;
    }
    if(t->r)
    {
        for(int i=t->val-1;i>=0;i--)
            t->inv+=t->r->cnt[i];
        for(int i=0;i<5;i++)t->cnt[i]+=t->r->cnt[i];
        t->inv+=t->r->inv ;
    }
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
    if(!t)return void(l=r=NULL);
    push(t);
    int cur=findsz(t->l)+1+add ;
    if(cur<=pos)split(t->r,t->r,r,pos,cur),l=t ;
    else split(t->l,l,t->l,pos,add),r=t ;
    updsz(t);
    if(t->l)push(t->l);
    if(t->r)push(t->r);
    update(t);
}
void merge(pnode &t,pnode l,pnode r)
{
    push(l);
    push(r);
    if(!l||!r)t=l?l:r;
    else if(l->rnk>r->rnk)merge(l->r,l->r,r),t=l ;
    else merge(r->l,l,r->l),t=r ;
    updsz(t);
    if(t->l)push(t->l);
    if(t->r)push(t->r);
    update(t);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,a,b,typ ;
    char c ;
    pnode root = NULL ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> c ;
        merge(root,root,new node(c-'0'));
    }
    while(m--)
    {
        cin >> typ ;
        if(typ==1)
        {
            cin >> a >> b >> c ;
            pnode L=NULL,R=NULL ;
            split(root,root,R,b);
            split(root,L,root,a-1);
            root->lazy=c-'0' ;
            merge(root,L,root);
            merge(root,root,R);
        }
        else if(typ==2)
        {
            cin >> a >> b ;
            pnode L=NULL,R=NULL ;
            split(root,root,R,b);
            split(root,L,root,a-1);
            root->rev^=1 ;
            merge(root,L,root);
            merge(root,root,R);
        }
        else
        {
            pnode L=NULL,R=NULL ;
            cin >> a >> b ;
            split(root,root,R,b);
            split(root,L,root,a-1);
            cout << root->inv << '\n' ;
            merge(root,L,root);
            merge(root,root,R);
        }
    }
}
