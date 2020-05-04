#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const int N = 1e9+7 ; 
map<int,int> mp ; 
//bool vst[N];
int main()
{
	int n = 100000 ; 
	vector<int> V;
	for(int i=1;i<=n;i++) {
		V.push_back(i);
	} 
	random_shuffle(V.begin(),V.end());
	int cnt = 0 ; 
	for(int i=0;i<V.size()-1;i++) {
		for(int j=i+1;j<V.size();j++) {
			if(V[i]>V[j]) {
				cnt++;
			}
		}
	}
	cout << cnt ; 
}