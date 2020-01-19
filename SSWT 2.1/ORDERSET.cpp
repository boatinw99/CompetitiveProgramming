#include<bits/stdc++.h>
using namespace std ;
struct node
{
    int val,rnk,sz ;
    node *l,*r ;
};
typedef node * pnode ;
map<int,int> mp ;
pnode init(int val)
{
    pnode ret = new node ;
    ret->val=val,ret->rnk=rand(),ret->sz=1,ret->l=ret->r=NULL;
    return ret ;
}
int findsz(pnode t)
{
    return t?t->sz:0;
}
void updatesz(pnode t)
{
    if(t)t->sz=findsz(t->l)+findsz(t->r)+1;
}
void split(pnode t,pnode &l,pnode &r,int key)
{
    if(!t)l=r=NULL;
    else if(t->val<=key)split(t->r,t->r,r,key),l=t;
    else split(t->l,l,t->l,key),r=t ;
    updatesz(t);
}
void merge(pnode &t,pnode l,pnode r)
{
    if(!l||!r)t=l?l:r;
    else if(l->rnk<r->rnk)merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    updatesz(t);
}
void insert(pnode &t,pnode it)
{
    if(!t)t=it ;
    else if(t->rnk<it->rnk)split(t,it->l,it->r,it->val),t=it;
    else insert(t->val<it->val?t->r:t->l,it);
    updatesz(t);
}
void erase(pnode &t,int key)
{
    if(!t)return ;
    else if(t->val==key){pnode tmp=t;merge(t,t->l,t->r);free(tmp);}
    else erase(t->val<key?t->r:t->l,key);
    updatesz(t);
}
int kth(pnode t,int k)
{
    if(t->l&&t->l->sz>=k)return kth(t->l,k);
    else if(t->r)
    {
        if(t->l&&t->l->sz+1<k)
        {
            return kth(t->r,k-1-t->l->sz);
        }
        else if(!t->l&&k>1)return kth(t->r,k-1);
    }
    return t->val ;
}
int count(pnode t,int k)
{
    //while((t&&t->l&&t->l->val>=t->val)||(t&&t->r&&t->r->val<=t->val));
    int tmp = 0 ;
    if(!t)return 0 ;
    if(t->val<=k)
    {
        tmp++;
        if(t->l)tmp+=t->l->sz;
        if(t->r)tmp+=count(t->r,k);
        return tmp ;
    }
    else if(t->l)return count(t->l,k);
    return 0 ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);;
    int n,m,i,j,x ;
    pnode root = NULL ;
    char c ;
    cin >> m ;
    while(m--)
    {
        cin >> c >> x ;
        if(c=='I')
        {
            if(mp[x]==0)
            {
                mp[x]++;
                insert(root,init(x));
            }
        }
        else if(c=='D')
        {
            if(mp[x]==1)
            {
                mp[x]=0;
                erase(root,x);
            }
        }
        else if(c=='K')
        {
            if(!root)cout << "invalid" << '\n' ;
            else if(root->sz<x)cout << "invalid" << '\n' ;
            else cout << kth(root,x) << '\n' ;
        }
        else
        {
            cout << count(root,x-1) << '\n' ;
        }
    }
}
