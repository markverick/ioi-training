#include<bits/stdc++.h>
using namespace std;
//int k[12000];
int hsh[1200000];
int main()
{
    int T,t,i,j;
    int n,h,q;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        //memset(k,0,sizeof k);
        scanf("%d %d %d",&n,&h,&q);
        memset(hsh,0,sizeof hsh);
        //map<int,bool> hsh;
        set<int> k;
        set<int> ::iterator it;
        for(i=0;i<h;i++)
        {
            int in;
            scanf("%d",&in);
            hsh[in]=1;
            k.insert(in);
        }
        //sort(&k[0],&k[h]);
        for(i=0;i<q;i++)
        {
            //map<int,bool> chk;
            int m,cot=0;

            scanf("%d",&m);
            for(it=k.begin();it!=k.end();it++)
            {
                int a=*it;
                if(a+m>=n)
                    break;
                if(hsh[a+m]==1)
                {
                    cot++;
                }
            }
            printf("%d ",cot);
        }
        printf("\n");
    }
}
