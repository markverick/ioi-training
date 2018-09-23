#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
int r,b,l;
int jum[2000][350][12];
int dp(int score,int game,int wcot)
{
    if(game*6+5<score||score<0||game<0)
        return 0;
    if(jum[score][game][wcot]>=0)
        return jum[score][game][wcot];
    //if(score>1840)
      //  return 0;
    if(score==0&&game==0)
    {
        return 1;
    }
    int sum=0;
    if(score-6>=0&&game-1>=0)
        sum+=dp(score-6,game-1,wcot);
    sum%=1000000007;
    if(score-4>=0&&game-1>=0)
        sum+=dp(score-4,game-1,wcot);
    sum%=1000000007;
    if(game-1>=0)
        sum+=dp(score,game-1,wcot);
    sum%=1000000007;
    if(wcot-1>=0&&game-1>=0)
        sum+=dp(score,game-1,wcot-1);
    sum%=1000000007;
    return jum[score][game][wcot]=sum;
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    memset(jum,-1,sizeof jum);
    while(T--)
    {

        scanf("%d %d %d",&r,&b,&l);
        printf("%d\n",dp(r,b,l));
    }
}

