#include<bits/stdc++.h>
using namespace std;
int x,y,n,w;
double pa,pb;
double jum[1135][1135];
double dp(int score,int time)
{
    if(score<=0)
    {
        return (double)1;
    }
    if(time<=0)
    {
        return (double)0;
    }
    if(jum[score][time]>=0)
        return jum[score][time];
    return jum[score][time]=max((double)pa*dp(score-x,time-1)/100+((double)100-pa)*dp(score,time-1)/100 ,
                        pb*dp(score-y,time-1)/100+(100-pb)*dp(score,time-1)/100 );
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d %d %d %d %lf %lf",&x,&y,&n,&w,&pa,&pb);
        //cout << dp(w,n) << "\n";
        printf("%.6f\n",dp(w,n)*100);
    }
}
