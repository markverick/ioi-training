#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
int a[120000];
int chk[120000];
vector<int> out;
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        memset(chk,-1,sizeof chk);
        out.clear();
        int n;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            int c=i;
            if(chk[c]==1)
                continue;
            chk[c]=1;
            int cot=0;
            while(true)
            {
                cot++;
                if(chk[a[c]]==1)
                    break;
                chk[a[c]]=1;
                c=a[c];
            }
            out.push_back(cot);
            printf("%d\n",cot);
        }/*
        long long lcm=out[0];
        long long gcd=out[0];
        for(i=1;i<out.size();i++)
        {
            __lcm(lcm,out[i]);
            gcd=lcm
        }
        long long mul=*/
        //printf("%d\n",cot);
    }
}

