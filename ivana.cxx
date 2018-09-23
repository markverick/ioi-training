#include<bits/stdc++.h>
using namespace std;
int a[111],b[111],jum[111][111];
int dp(int fst,int lst,int turn)/// turn 1 = me
{
    if(jum[fst][lst]>=0)
        return jum[fst][lst];
    if(fst>lst)
        return 0;
    if(turn)
        return jum[fst][lst]=max(dp(fst+1,lst,1-turn)+b[fst]%2,dp(fst,lst-1,1-turn)+b[lst]%2);
    else
        return jum[fst][lst]=min(dp(fst+1,lst,1-turn),dp(fst,lst-1,1-turn));
}
int main()
{
	int i,j,k,n,tmp,cot=0,odd=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]%2)
            odd++;
    }
    for(i=1;i<=n;i++)
    {
        memset(jum,-1,sizeof jum);
        k=1;
        for(j=i+1;j<=n;j++)
            b[k++]=a[j];
        for(j=1;j<i;j++)
            b[k++]=a[j];
        k=dp(1,n-1,0)+a[i]%2;
        if(k>odd-k)
            cot++;
    }
    printf("%d",cot);
}
