#include<stdio.h>
#include<algorithm>
using namespace std;
int a,b;
int fk=0;
int c[200000],p[200000];
int prime[200000],factor[200000],nf=0,np=0;
int fx(int n)
{
    int i,hi;
    for(i=0;true;i++)
    {
        if(n%p[i]==0)
        {
            fx(n-p[i]);
        }
    }

}
int main()
{
    int i,j,k,idx=0;
    scanf("%d %d",&a,&b);
    nf=idx;
    idx=0;
    int chk=0;

    for(i=2;i<=b;i++)
    {
        if(c[i]==0)
        {
            p[idx++]=i;
            for(j=i+i;j<=b;j+=i)
                c[j]=1;
        }
    }
    np=idx;
    for(i=0;i<np;i++)
    {
        printf("%d ",p[i]);
    }
    //printf("%d",fx(b));
}
