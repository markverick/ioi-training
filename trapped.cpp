#include<bits/stdc++.h>
using namespace std;
#define MP make_pair
pair<int,int> dat[5000];
int main()
{
    freopen("trapped.in","r",stdin);
    freopen("trapped.out","w",stdout);
    int n=0;
    int cot=0;
    scanf("%d",&n);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        dat[i]=MP(b,a);
    }
    sort(&dat[0],&dat[n]);
    for(i=0;i<n;i++)
    {
        int d=dat[i+1].first-dat[i].first;
        int fst=i;
        int lst=i+1;
        int fu=0;
        //printf("E");
        while(true)
        {
            //printf("F");
            if(fst<0)
                break;
            if(lst>=n)
                break;

            if(d>dat[lst].second)
            {
                lst=lst+1;
                d=dat[lst].first-dat[fst].first;
            }
            else if(d>dat[fst].second)
            {
                fst=fst-1;
                d=dat[lst].first-dat[fst].first;
            }
            else
            {
                fu=1;
                break;
            }

        }
        if(fu==1)
            {
                cot+=dat[i+1].first-dat[i].first;
            }
    }
    printf("%d",cot);

}
