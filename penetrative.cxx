#include<bits/stdc++.h>
#define MP make_pair
#define X first
#define Y second
using namespace std;
int y,x,n;
long long a[1200];
int jum[100135];
queue<pair<int,long long> > q;
int main()
{
    int i,j,k;
    scanf("%d %d",&y,&x);
    y%=100000;
    x%=100000;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    q.emplace(0,y);
    long long z=0,tmp;
    int idx=0;
    memset(jum,-1,sizeof jum);
    while(!q.empty())
    {
        tie(idx,z)=q.front();
        q.pop();
        //printf("[%d]= %d\n",idx,z);
        if(z==x)
        {
            printf("%d",idx);
            return 0;
        }
        for(i=0;i<n;i++)
        {
            tmp=(z*a[i])%100000;
            if(jum[tmp]==-1)
            {
                jum[tmp]=idx+1;
                q.emplace(idx+1,tmp);
            }

        }
    }
    printf("-1");
}
