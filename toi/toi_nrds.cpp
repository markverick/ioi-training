#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int i;
int result[24];
int chk[24];
char jum[1000][10];
int cot=0;
void gen(int idx)
{
    int j;
    if(idx==i)
    {
        /*
        for(j=0;j<i;j++)
            printf("%d",result[j]);
        printf("\n");
        */
        cot++;
        for(j=0;j<i;j++)
            jum[cot][j]=result[j];
        return;
    }
    for(j=1;j<=9;j++)
    {
        if(chk[j]==1||(idx>=1&&j<=result[idx-1]))
            continue;
        chk[j]=1;
        result[idx]=j;
        gen(idx+1);
        chk[j]=0;
        //system("pause");
    }

}
int main()
{
    int j,k,t,T;
    scanf("%d",&T);
    for(i=1;i<=9;i++)
    {
        gen(0);
    }
    //printf("%d",cot);
    //system("pause");
    for(t=0;t<T;t++)
    {
        scanf("%d",&n);
        if(n>cot)
        {
            printf("-1\n");
            continue;
        }
        for(j=0;jum[n][j]!=0;j++)
            printf("%d",jum[n][j]);
        printf("\n");
    }
}
