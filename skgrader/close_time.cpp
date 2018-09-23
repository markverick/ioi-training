#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
pair <int,int> dat[120000];
int t[120000],b[120000];
int counter[10000];
int main()
{
    int idx=0;
    int n,c;
    scanf("%d %d",&n,&c);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&t[i],&b[i]);
        dat[idx++]=MP(t[i],b[i]);
    }
    sort(&dat[0],&dat[n]);
    /*for(i=0;i<n;i++)
    {
        printf("%d %d\n",dat[i].first,dat[i].second);
    }*/
    idx=0;
    int cot=0;
    for(i=1;true;i++)
    {
        //printf("%d\n",cot);

        if(i<dat[idx].first)
        {

            continue;

        }

        cot=0;
        for(j=0;j<c;j++)
        {
            if(counter[j]<=i)
            {
                if(cot==0)
                    counter[j]=i+dat[idx].second;
                cot++;
            }
        }
        if(cot!=0)
            idx++;
        //printf("%d %d\n",idx,c);
        //system("pause");
        if(idx>=n&&cot==c)
        {
            printf("%d\n",i);
            break;
        }
    }
}
