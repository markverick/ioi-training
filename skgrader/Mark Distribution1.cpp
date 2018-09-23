#include<bits/stdc++.h>

int n,t,p;
int cot=0;
void fx(int idx,int sum)
{
    int i;
    //printf("%d %d\n",idx,sum);
    if(idx==n&&sum>=t)
    {
        cot++;
        return;

    }
    if(idx>n)
        return;
    for(i=p;i<=t-sum;i++)
    {
        //result[idx]=i;
        fx(idx+1,sum+i);
    }
}
int main()
{
    int ti,i;
    scanf("%d",&ti);
    for(i=0;i<ti;i++)
    {
        cot=0;
        scanf("%d %d %d",&n,&t,&p);
        fx(0,0);
        printf("%d\n",cot);
    }




}
