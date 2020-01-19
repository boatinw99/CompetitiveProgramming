#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ,inf = 1e9+7 ;
int a[N],n;
set<int> S ;
struct node
{
    int rnk,val,sz,mask[4],len;
    struct node *l,*r ;
    node(int val,int len):
        val(val),len(len),rnk(rand()),sz(1),l(NULL),r(NULL),mask({0,inf,inf,len}){}
};
typedef struct node * pnode ;
pnode root = NULL ;
int findsz(pnode t)
{
    return t?t->sz:0 ;
}
void update(pnode t)
{
    if(!t)return ;
    t->sz=findsz(t->l)+findsz(t->r)+1 ;
    t->mask[0]=0,t->mask[1]=t->mask[2]=inf,t->mask[3]=t->len ;
    if(t->l)
    {
        if((t->l->sz)&1)///even
        {
            t->mask[0]=min(t->l->mask[1],t->l->mask[0]);
            t->mask[1]=t->l->mask[0]+t->len;
            t->mask[2]=t->l->mask[3];
            t->mask[3]=t->l->mask[2]+t->len;
        }
        else
        {
            t->mask[0]=min(t->l->mask[1]+t->mask[0],inf);
            t->mask[1]=t->l->mask[0]+t->len;
            t->mask[2]=min(t->l->mask[3],t->l->mask[2]);
            t->mask[3]=t->l->mask[2]+t->len;
        }
    }
    if(t->r)
    {
        int szl = (findsz(t->l)+1)&1 ;
        int szr = (t->r->sz)&1 ;
        int tmp[4];
        for(int i=0;i<4;i++)tmp[i]=t->mask[i];
       // printf("chk %d | %d %d %d %d \n",t->val,t->mask[0],t->mask[1],
         //  t->mask[2],t->mask[3]);
        if(szl&&szr)
        {
            tmp[0]=min(t->mask[1]+t->r->mask[0],t->mask[0]+t->r->mask[2]);
            tmp[0]=min(tmp[0],t->mask[0]+t->r->mask[0]);
            tmp[1]=t->mask[0]+t->r->mask[3];
            tmp[2]=t->mask[3]+t->r->mask[0];
            tmp[3]=min(t->mask[2]+t->r->mask[3],t->mask[3]+t->r->mask[1]);
        }
        else if(szl==0&&szr==0)
        {
            tmp[0]=min(t->mask[1]+t->r->mask[0],t->mask[0]+t->r->mask[2]);
            tmp[1]=t->mask[1]+t->r->mask[1];
            tmp[2]=t->mask[2]+t->r->mask[2];
            tmp[3]=min(t->mask[2]+t->r->mask[3],t->mask[3]+t->r->mask[1]);
            tmp[3]=min(tmp[3],t->mask[2]+t->r->mask[1]);
        }
        else if(szl==1&&szr==0)
        {
            tmp[0]=min(inf,t->mask[0]+t->r->mask[2]);
            tmp[1]=min(t->mask[1]+t->r->mask[1],t->mask[0]+t->r->mask[3]);
            tmp[1]=min(tmp[1],t->mask[0]+t->r->mask[1]);
            tmp[2]=min(t->mask[2]+t->r->mask[2],t->mask[3]+t->r->mask[0]);
            tmp[3]=min(inf,t->mask[3]+t->r->mask[1]);
        }
        else
        {
            tmp[0]=min(t->mask[1]+t->r->mask[0],inf);
            tmp[1]=min(t->mask[1]+t->r->mask[1],t->mask[0]+t->r->mask[3]);
            tmp[2]=min(t->mask[2]+t->r->mask[2],t->mask[3]+t->r->mask[0]);
            tmp[2]=min(tmp[2],t->mask[2]+t->r->mask[0]);
            tmp[3]=min(t->mask[2]+t->r->mask[3],inf);
        }
        for(int i=0;i<4;i++)t->mask[i]=tmp[i];
    }
}
void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t)l=r=NULL;
    else if(t->val<=key)split(t->r,t->r,r,key),l=t ;
    else split(t->l,l,t->l,key),r=t;
    update(t);
}
void merge(pnode &t,pnode l,pnode r)
{
    if(!l||!r)t=l?l:r ;
    else if(l->rnk>r->rnk)merge(l->r,l->r,r),t=l ;
    else merge(r->l,l,r->l),t=r ;
    update(t);
}
void add(int pos)
{
    auto it = S.lower_bound(pos);
    pnode R1=NULL,R2=NULL ;
    if(it!=S.begin()&&it!=S.end())
    {
        auto it1=it ;
        it1--;
        split(root,root,R2,*it1);
        split(root,root,R1,*it1-1);
        merge(root,root,new node(*it1,a[pos]-a[*it1]));
        merge(root,root,new node(pos,a[*it]-a[pos]));
        merge(root,root,R2);
    }
    else if(it==S.begin())merge(root,new node(pos,a[*it]-a[pos]),root);
    else
    {
        it--;
        merge(root,root,new node(*it,a[pos]-a[*it]));
    }
    S.insert(pos);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++)cin >> a[i] ;
    for(int i=1;i<=n;i++)while(a[i]<a[i-1]);
    int x,y ;
    cin >> x ;
    S.insert(x);
    for(int i=2;i<=n;i+=2)
    {
        cin >> x >> y ;
        add(x),add(y);
        cout << min({root->mask[1],root->mask[2],root->mask[3]}) << '\n' ;
    }
    return 0 ;
}
