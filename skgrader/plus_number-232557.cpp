#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
bool notPrime[1200000];
int prime[1200000];
int len=0;
int jum[120000];
queue<pair<int,int> >q;
//idx step
int chk[100050];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j,k;
    int idx=0;
    notPrime[1]=1;
    for(i=2;i<=100005;i++)
    {
        if(!chk[i])
        {
            prime[idx++]=i;
            for(j=i+i;j<=100005;j+=i)
                chk[j]=1;
        }
    }
    len=idx;
    q.push(MP(n,0));
    int cot=0;
    jum[n]=0;
    while(!q.empty())
    {
        idx=q.front().first;
        int step=q.front().second;
        int b4=idx;
        //printf("%d\n",idx);
        q.pop();
        if(idx>m)
            continue;
        if(idx==m)
        {
            printf("%d\n",step);
            exit(0);
        }
        //jum[idx]=1;
        cot=0;
        for(i=0;prime[i]<b4;i++)
        {
            //printf("%d\n",idx);
            if(idx%prime[i]==0)
            {
                cot=0;
                while(idx%prime[i]==0)
                {
                    idx=idx/prime[i];
                }
                //jum[idx]=jum[b4]+cot;
                //printf("%d\n",prime[i]);

                if(jum[b4+prime[i]]==0&&b4+prime[i]<=m)
                {
                    jum[b4+prime[i]]=1;
                    q.push(MP(b4+prime[i],step+1));
                }
                    //196 98 49 3 // q = 196 198
            }


        }
    }
    printf("-1");
}
