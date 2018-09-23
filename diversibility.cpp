#include<bits/stdc++.h>
int mod=0;
int chk=0;
int num[12000];
int m;
bool jum[12000][12000];
void fx(int idx,int sum)
{
    if(jum[idx][sum]==1)
        return;
    if(idx==m)
    {
        if(sum%mod==0)
            chk=1;
        return;
    }
    int n=num[idx];
    if(idx!=1)
    {
        fx(idx+1,sum-n);jum[idx+1][sum-n]=1;
    }

    fx(idx+1,sum+n);jum[idx+1][sum+n]=1;


}
int main()
{
    int i,ti,t;
    scanf("%d",&ti);
    for(t=0;t<ti;t++)
    {
        chk=0;mod=0;m=0;
        memset(jum,0,sizeof jum);
        memset(num,0,sizeof num);
        scanf("%d %d",&m,&mod);
        for(i=0;i<m;i++)
        {
            scanf("%d",&num[i]);
        }
        fx(0,0);
        if(chk==1)
            printf("Divisible\n");
        else
            printf("Not divisible\n");
    }
}
