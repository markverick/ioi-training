#include "tourist.h"
#include<stdio.h>
int dp(int idx,int money)
{
    if(idx<4999&&money<4999&&jum[idx][money]>=0)
        return jum[idx][money];
    if(money>=k)
    {
        return 0;
    }
    if(idx<4999&&money<4999)
        return jum[idx][money] = max(dp(idx+1,money+2)+h[idx],dp(idx+1,money+1));
    else
        return max(dp(idx+1,money+2)+h[idx],dp(idx+1,money+1));
}
int GreaterHappiness(int N, int K, int *H){

    int n=N,k=K;
    int h[];
    int jum[5000][500];
    dp(0,0);
    return 0;
}
