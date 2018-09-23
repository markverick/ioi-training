#include<bits/stdc++.h>

int n,t,p;
int cot=0;
int jum[200][200];
int fx(int idx,int sum)
{
    int i;
    if(jum[idx][sum]>=0)
    {
        return jum[idx][sum];
    }
    //printf("%d %d\n",idx,sum);
    if(idx==n&&sum>=t)
    {
        return 1;

    }
    if(idx>n)
        return 0;
    int temp=0;
    for(i=p;i<=t-sum;i++)
    {
        //result[idx]=i;
        temp +=fx(idx+1,sum+i);//return jum[idx][sum] =
    }
    return jum[idx][sum] = temp;
}
int main()
{
    int ti,i;
    scanf("%d",&ti);
    for(i=0;i<ti;i++)
    {

        memset(jum,-1,sizeof jum);
        scanf("%d %d %d",&n,&t,&p);
        printf("%d\n",fx(0,0));
    }




}
