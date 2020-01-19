#include<bits/stdc++.h>
using namespace std ;
const double EPS = 1e-9;
const int N = 509;
int n;
double a[N][N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    double det = 1;
    cin >> n ;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin >> a[i][j];
    for (int i=0;i<n;i++)
    {
        int k = i;
        for(int j=i+1;j<n;j++)if(abs(a[j][i])>abs(a[k][i]))k=j;
        if(abs(a[k][i])<EPS)
        {
            det = 0;
            break;
        }
        swap(a[i],a[k]);
        if(i!=k)det*=-1;
        det*=a[i][i];
        for(int j=i+1;j<n;j++)a[i][j]/=a[i][i];
        for(int j=0;j<n;j++)if(j!=i&&abs(a[j][i])>EPS)
            for(int k=i+1;k<n;k++)a[j][k]-=a[i][k]*a[j][i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << a[i][j] << " " ;
        }
        cout << '\n' ;
    }
    cout << det;
}
