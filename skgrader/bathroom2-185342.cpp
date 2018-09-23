#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[120000];
int main()
{
    int i,j,k;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(&a[0],&a[m]);
    long long fst=0;
    long long lst=1234567890123456789;
    long long mid;
    long long jum=1234567890123456789;
    while(fst<lst)
    {

        unsigned long long sum=0;
        mid=(fst+lst)/2;
        //printf("%d %d %d\n",fst,mid,lst);
        for(i=0;i<m;i++)
        {
            sum+=mid/a[i];
            if(sum>1000000000)
                break;
        }
        if(sum<n)
        {
            fst=mid+1;
        }
        else
        {
            jum=min(jum,mid);
            lst=mid;
        }
    }
    printf("%llu",jum);
}
