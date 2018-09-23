#include<bits/stdc++.h>

using namespace std;
char str[500000];
char str2[500000];
long long idx;
long long jum[100000];
int main()
{
    long long n,i,j;
    scanf("%lld",&n);
    for(i=1;i<=70000;i++)
    {
        //memset(str2,0,sizeof str2);
        long long k;
        //mergeNum(); //i=10; //256
        for(k=0,j=i;j>=1;j/=10,k++)
        {
            str2[k]=j%10;
        }
        jum[i]=jum[i-1]+k;

        for(j=k-1;j>=0;j--)
        {

            str[idx++]=str2[j];
        }
        /*
        for(j=0;j<idx;j++)
            printf("%d",str[j]);
        printf("\n");

        system("pause");
*/
        //str[idx++]=
    }
    //printf("%d\n",idx);
    long long num;
    long long b4;
    /*for(i=1;i<50;i++)
    {
        printf("%d\n",jum[i]);
    }*/
    for(i=0;i<n;i++)
    {
        scanf("%lld",&num);
        b4=num;
        if(num==1)
        {
            printf("1\n");
            continue;
        }
        jum[0]=1;
        for(j=1;true;j++)
        {

            if(num<=0)
            {

                printf("%d\n",str[num+jum[j-1]-1]);
                //printf("%d\n",b4-jum[j-1]);
                break;
            }
            num-=jum[j];
        }
    }
}
