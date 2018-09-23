#include<bits/stdc++.h>
int result[15];
int n,m;
int flippinCount=0;
int chck[10]; //prohibited foods chckKKKKKKKK
int love[10]; //non prohibited foods <3
int check[40];
void dp(int idx)
{
    int i;
    if(flippinCount>=100000)return;
    if(idx==n+1)
    {

        for(i=1;i<=n;i++)
        {
            printf("%d ",result[i]);
        }
        flippinCount++;
        printf("\n");
        //memset(check,0,40);
        return;
    }
    else if(idx==1)
    {

        for(int i=1;i<=n-m;i++)
        {
            if(check[love[i]])
                continue;

            result[1]=love[i];
            check[love[i]]=1;
            dp(idx+1);
            check[love[i]]=0;
        }
    }
    else
    {

        for(int i=1;i<=n;i++)
        {

            if(check[i])
                continue;

            result[idx]=i;
            check[i]=1;
            dp(idx+1);
            check[i]=0;
        }
    }
}
int hsh[100];
int main()
{

    int i,j,k=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&chck[i]);
        chck[i];
        hsh[chck[i]]=1;
    }
    int idx=1;
    for(i=1;i<=n;i++)
    {
        if(hsh[i]==0)
        {
            love[idx++]=i;
        }
    }
    /*for(i=1;i<=n-m;i++)
    {
        printf("%d ",love[i]);
    }*/
    dp(1);

/*
    for(i=1,j=1;i<=n;i++)
    {
        if(i!=chck[j])love[idx++]=i;
        if(i+1>chck[j])j++;
    }
    for(i=1;i<=n-m;i++)
    {
        printf("%d ",love[i]);
    }
    //gen(0);
    */
}
