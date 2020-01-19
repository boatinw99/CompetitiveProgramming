#include<bits/stdc++.h>
using namespace std ;
const int N = 5e3+9 ;
char
 a[N],c[N];
vector<int> type[4];
vector<int> a1,a2,a3,a4 ;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,m ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> c[i];
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)
    {
        if(c[i]=='0'&&a[i]=='0')type[0].emplace_back(i);
        if(c[i]=='0'&&a[i]=='1')type[1].emplace_back(i);
        if(c[i]=='1'&&a[i]=='0')type[2].emplace_back(i);
        if(c[i]=='1'&&a[i]=='1')type[3].emplace_back(i);
    }
    for(auto it:type[1])a1.emplace_back(it);
    for(auto it:type[2])a2.emplace_back(it);
    ///a1 -> 01 (acrobat) ,, a2 -> 10 (crown)
    for(auto it:type[3])
    {
        if(a1.size()+a3.size()<=a2.size()+a4.size())a3.emplace_back(it);
        else a4.emplace_back(it);
    }
    ///a3-> 11 in second performance
    int cnta=a1.size()+a3.size(),cntb=a2.size()+a4.size();
    while(cntb>cnta&&!a2.empty())
    {
        cntb--;
        a3.emplace_back(a2.back());
        a2.pop_back();
    }
    while(cnta>cntb&&!a1.empty())
    {
        cnta--;
        a4.emplace_back(a1.back());
        a1.pop_back();
    }
    //printf("aaa %d %d\n",cnta,cntb);
    if(cnta!=cntb)cout << "-1" ;
    else
    {
        for(auto it:type[0])
        {
            if(a1.size()+a3.size()<=a2.size()+a4.size())a3.emplace_back(it);
            else a4.emplace_back(it);
        }
        if(a1.size()+a3.size()!=a2.size()+a4.size())
        {
            cout << "-1";
        }
        else
        {
            for(auto it:a2)cout << it << " " ;
            for(auto it:a4)cout << it << " ";
        }
    }
}
