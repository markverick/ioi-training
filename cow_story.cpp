#include<bits/stdc++.h>
int year;
int cot=0;
int temp=0;
int fx(int idx)
{
    int i;
    if(idx<=0)
    {
        return 1;
    }
    temp=0;
    for(i=0;i<idx;i++)
    {
        temp+=fx(i);
    }
    return temp;
}
int main()
{
    int sum=0;
    int i,j,k;
    scanf("%d",&year);
    for(j=0;j<year;j++)
    {
        sum++;
        for(i=j+4;i<year;i+=4)
        {
            sum+=fx((year-i)/3);
        }
    }
    /*for(i=0;i<10;i++)
    {
        printf("fx(%d) = %d\n",i,fx(i));
    }
    */
    printf("%d",sum);
}
