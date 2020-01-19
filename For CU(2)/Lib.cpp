#include<bits/stdc++.h>
using namespace std ;
main()
{
    string s,f,g;
    int k=0;
    map<pair<string,string>,pair<int,int> > p ;
    map<pair<string,string>,pair<int,int> >::iterator it ;
    
	while(!0)
    {
        cin >> s ;
        if(s=="-1")break;
        else
        {
            if(s=="add")
            {
                cin >> f >> g ;
                p[{f,g}].first++;
                p[{f,g}].second++;
            }
            else if(s=="check")
            {
            	cin >> f >> g ;
            	cout << p[{f,g}].second << endl;
			}
			else if(s=="borrow")
			{
				cin >> f >> g ;
				if(p[{f,g}].second<=0)cout << "Error" << endl ;
				else p[{f,g}].second-- ;
			}
			else if(s=="return")
			{
				cin >> f >> g ;
				if(p[{f,g}].second>=p[{f,g}].first)cout << "Error" << endl;
				else p[{f,g}].second++ ;
			}
			else if(s=="search")
			{
				k=0;
				cin >> g ;
				for(it=p.begin();it!=p.end();it++)
				{
					if(it->first.second == g)
					{
						cout << it->first.first << " " << it->second.second << endl ;
						k=99;
					}			
				}
				if(k!=99) cout << "Error" << endl ;
			}
			else cout << "Error" << endl ;
        }
    }

}
