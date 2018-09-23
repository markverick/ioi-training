#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[8]={0,1,4,6,3,5,2};
long long b[8];
long long d[8]={0,6,2,5,4,1,3};
//long long d[8]={0,5,2,6,4,3,1};
//long long sh[8]={0,4,2,1,6,5,3};
//long long shi[8]={0,3,2,6,1,5,4};
long long sh[8]={0,4,1,2,3,5,6};
long long shi[8]={0,2,3,4,1,5,6};
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long r,c,i,j,k,l,sum=0,x;
    scanf("%lld %lld",&r,&c);
    for(i=1;i<=r;i++)
    {
        x=0;
        for(j=1;j<=4;j++)
            x+=a[j];
        x*=(c-1)/4;
        k=(c-1)%4+1;
        if(i%2)
        {
            for(j=1;j<=k;j++)
                x+=a[j];
        }
        else
        {
            for(j=4;j>4-k;j--)
                x+=a[j%4+1];
        }
//        for(j=1;j<=6;j++)
//        {
//            printf("%lld - ",a[j]);
//        }
//        printf("\n");
        for(l=1;l<k;l++)
        {
            for(j=1;j<=6;j++)
                if(i%2)
                    b[sh[j]]=a[j];
                else
                    b[shi[j]]=a[j];
            for(j=1;j<=6;j++)
                a[j]=b[j];
        }
        sum+=x;
//        for(j=1;j<=6;j++)
//        {
//            printf("%lld - ",a[j]);
//        }
//        printf("\n");
        for(j=1;j<=6;j++)
            b[d[j]]=a[j];
        for(j=1;j<=6;j++)
            a[j]=b[j];
//        for(j=1;j<=6;j++)
//        {
//            printf("%lld - ",a[j]);
//        }
//        printf("\n");
//        printf("%lld\n",x);
    }
    printf("%lld",sum);
}
