#include<stdio.h>
long long jum[100000000];
int main()
{
    long long n,a,b;
    int i,j,k;
    int now=0;
    int fst=0,lst=0;
    jum[1]=1;
    jum[2]=1;
    while(true)
    {
        scanf("%lld %lld",&a,&b);

        int f=0;
        for(i=1;true;i++)
        {

            //if(jum[i]==0)
            if(i>2)
                jum[i]=jum[i-1]+jum[i-2];

            if(f==0&&jum[i]>=a)
            {
                fst=i;
                f=1;
            }
            if(jum[i]>b)
            {
                lst=i;
                now=i;
                break;
            }
            //printf("%d\n",jum[i]);
        }
        printf("%d\n",lst-fst);
    }


}
