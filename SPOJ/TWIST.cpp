#include<bits/stdc++.h>
using namespace std ;
int n ; 
struct item {
    int val,sz,prior,lazy;
    item *l,*r;
    item(int val): val(val),lazy(0),prior(rand()),l(NULL),r(NULL) {}
};
typedef item * pitem ; 
int getsz(pitem t) {
    return t?t->sz:0;
}
void push(pitem t) {
    if(t&&t->lazy) {
        t->lazy=0;
        swap(t->l,t->r);
        if(t->l)t->l->lazy^=1;
        if(t->r)t->r->lazy^=1;
    }
}
void upd(pitem t) {
    if(t) {
        t->sz = getsz(t->l)+getsz(t->r)+1;
    }
}
void split(pitem t, pitem &l, pitem &r, int key, int add=0) {
    push(t);
    if(!t)return void(l=r=NULL);
    int cur = getsz(t->l)+add+1;
    if(cur<key)split(t->r,t->r,r,key,cur),l=t;
    else split(t->l,l,t->l,key,add),r=t;
    upd(t);
}
void merge(pitem &t, pitem l, pitem r) {
    push(l),push(r);
    if(!l||!r)t=l?l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd(t);
}
void print(pitem t) {
    if(!t)return ; 
    push(t);
    print(t->l);
    cout << t->val << " " ;
    print(t->r);
}
int main() {
    ios::sync_with_stdio(false),cin.tie(0);
    int m ; 
    cin >> n >> m ; 
    pitem root = NULL ; 
    for(int i=1;i<=n;i++) {
        merge(root,root,new item(i));
    }
    for(int i=1;i<=m;i++) {
        int x,y ; 
        cin >> x >> y ;
        pitem R1 = NULL, R2=NULL; 
        split(root,root,R2,y+1);
        split(root,root,R1,x);
        R1->lazy^=1;
        merge(root,root,R1);
        merge(root,root,R2);
    }
    print(root);
    cout << '\n' ; 
    return 0 ; 
}
