#include<bits/stdc++.h>
using namespace std ;
const int N = 1009;
int Cu[N][N],Ag[N][N],Au[N][N];
int qsa[N][N],qsb[N][N],qsc[N][N];
int sldupa[N][N],sldupb[N][N],sldupc[N][N];
deque<pair<int,int> > dqa,dqb,dqc;
main()
{
    int n,k,i,j ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&Cu[i][j]);
            qsa[i][j]=qsa[i][j-1]+qsa[i-1][j]+Cu[i][j]-qsa[i-1][j-1];
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&Ag[i][j]);
            qsb[i][j]=qsb[i][j-1]+qsb[i-1][j]+Ag[i][j]-qsb[i-1][j-1];
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&Au[i][j]);
            qsc[i][j]=qsc[i][j-1]+qsc[i-1][j]+Au[i][j]-qsc[i-1][j-1];
        }
    for(i=k;i<=n;i++)
    {
        for(j=k;j<=n;j++)
        {
            Cu[i][j]=qsa[i][j]-qsa[i-k][j]-qsa[i][j-k]+qsa[i-k][j-k];
            Ag[i][j]=qsb[i][j]-qsb[i-k][j]-qsb[i][j-k]+qsb[i-k][j-k];
            Au[i][j]=qsc[i][j]-qsc[i-k][j]-qsc[i][j-k]+qsc[i-k][j-k];
        }
    }
    ///slideup
    for(j=k;j<=n;j++)
    {
        for(i=n;i>=k;i--)
        {
            while(!dqa.empty()&&dqa.front().second-i>=k)dqa.pop_front();
            while(!dqa.empty()&&dqa.back().first<Cu[i][j])dqa.pop_back();
            dqa.push_back({Cu[i][j],i});
            while(!dqb.empty()&&dqb.front().second-i>=k)dqb.pop_front();
            while(!dqb.empty()&&dqb.back().first<Ag[i][j])dqb.pop_back();
            dqb.push_back({Ag[i][j],i});
            while(!dqc.empty()&&dqc.front().second-i>=k)dqc.pop_front();
            while(!dqc.empty()&&dqc.back().first<Au[i][j])dqc.pop_back();
            dqc.push_back({Au[i][j],i});
            sldupa[i][j]=dqa.front().first;
            sldupb[i][j]=dqb.front().first;
            sldupc[i][j]=dqc.front().first;
        }
        dqa.clear();dqb.clear();dqc.clear();
    }
    int ans=0;
    for(i=k;i<=n;i++)
    {
        for(j=n;j>=k;j--)
        {
            while(!dqa.empty()&&dqa.front().second-j>=k)
                dqa.pop_front();
            while(!dqa.empty()&&dqa.back().first<sldupa[i][j])
                dqa.pop_back();
            dqa.push_back({sldupa[i][j],j});
            while(!dqb.empty()&&dqb.front().second-j>=k)
                dqb.pop_front();
            while(!dqb.empty()&&dqb.back().first<sldupb[i][j])
                dqb.pop_back();
            dqb.push_back({sldupb[i][j],j});
            while(!dqc.empty()&&dqc.front().second-j>=k)
                dqc.pop_front();
            while(!dqc.empty()&&dqc.back().first<sldupc[i][j])
                dqc.pop_back();
            dqc.push_back({sldupc[i][j],j});
            ans=max(dqa.front().first+dqb.front().first+
                    dqc.front().first,ans);
        }
        dqa.clear(); dqb.clear(); dqc.clear();
    }
    printf("%d",ans);
}
