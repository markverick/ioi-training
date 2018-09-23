#include<bits/stdc++.h>
#define MP make_pair
#define MT(x,y,z) make_pair(x,make_pair(y,z))
#define PB push_back
#define X first
#define Y second
using namespace std;
int n;
int kon[2200];
int hsh[2200];
int p[2200];
pair<int,pair<int,int> > score[2000005];
int find_(int x)
{
    while(p[x]!=x)
    {
        x=p[x];
    }
    return x;
}
void union_(int x,int y)
{
    x=find_(x);
    y=find_(y);
    if(rand()%2)
    {
        p[x]=y;
    }
    else
    {
        p[y]=x;
    }
}
int main()
{
    int i,j,k;
    srand(135);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&kon[i]);
    }
    int idx=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            score[idx++]=MT(kon[i]^kon[j],i,j);
        }
    }
    sort(&score[0],&score[idx]);
//    printf("%d",dp(0));
    for(i=0;i<n;i++)
        p[i]=i;
    long long sum=0;
    for(i=idx-1;i>=0;i--)
    {
        if(find_(score[i].Y.X)!=find_(score[i].Y.Y))
        {
            sum+=score[i].X;
            union_(score[i].Y.X,score[i].Y.Y);
        }
    }
    printf("%lld\n",sum);
}

