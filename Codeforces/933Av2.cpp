#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int m1,m2,op,n,m3,m4;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {
		scanf("%d",&op);
		if(op==1) ++m1,m3=max(m3,m2)+1;
		else if(op==2) m2=max(m2,m1)+1,m4=max(m3,m4)+1;
	}
	printf("%d\n",max(m3,m4));
}
