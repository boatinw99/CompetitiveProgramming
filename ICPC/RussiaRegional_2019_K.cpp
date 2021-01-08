#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 2e3+9 ; 
vector<pii> V ; 
int n,m,x,y ; 
char A[N][N]; 
pii get_range(int l,int r)
{
    pii ll = {1,n} ; 
    for(auto it:V)
    {
        if(it.se>=l&&it.se<=r)
        {
            if(it.fi<=x)ll.fi = max(ll.fi,it.fi+1); 
            if(it.fi>=x)ll.se = min(ll.se,it.fi-1);
        }
    }
    return ll ; 
}
void paint(int x1,int y1,int x2,int y2,char c)
{
    c+='a'-'A';
    for(int i=x1;i<=x2;i++)
    {
        for(int j=y1;j<=y2;j++)
        {
            if(A[i][j]=='.')A[i][j]=c ; 
        }
    }
}
void ordinary_paint(int l,int r,int x1,int x2)/// row l -> row r colum x1 -> x2 
{
    int befR=l ; 
    char clr = 0 ; 
    vector<pii> pp ; 
    if(l>r||x1>x2)return ; 
    for(int i=l;i<=r;i++)
    {
        bool ch = 0 ;
        int befC = x1; 
        pp.clear();
        for(int j=x1;j<=x2;j++)
        {
            if(A[i][j]!='.')
            {
                clr = A[i][j];
                pp.push_back({i,j});
                ch++;
                paint(befR,befC,i,j,clr);        
                befC = j+1 ; 
            }
        }
        if(ch)
        {
            paint(befR,befC,i,x2,clr);
            befR=i+1;
        }
    }
    int beff = x1 ; 
    for(auto it:pp)
    {
        paint(befR,beff,r,it.se,clr);
        beff = it.se+1;
    }
    paint(befR,beff,r,x2,clr);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> A[i][j] ;
            if(A[i][j]=='A')
            {
                x = i ;
                y = j ;
            }
            else if(A[i][j]>'A'&&A[i][j]<='Z')
            {
                V.push_back({i,j});    
            }
        }
    }
    pair<int,pii> ans = {0,{y,y}}; 
    for(int l=1;l<=y;l++)
    {
        for(int r=y;r<=m;r++)
        {
            pii gr = get_range(l,r);
            if(l>r)continue ;
            //printf("really ? %d %d || %d %d\n",l,r,gr.fi,gr.se);
            ans = max(ans,{(gr.se-gr.fi+1)*(r-l+1),{l,r}});
        }
    }
    pii res = get_range(ans.se.fi,ans.se.se);
    paint(res.fi,ans.se.fi,res.se,ans.se.se,'A'); 
    ordinary_paint(1,res.fi-1,1,m);
    ordinary_paint(res.se+1,n,1,m);
    ordinary_paint(res.fi,res.se,1,ans.se.fi-1);
    ordinary_paint(res.fi,res.se,ans.se.se+1,m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cout << A[i][j] ;
        cout << '\n' ;
    }
    return 0 ;
}