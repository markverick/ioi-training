#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
int n;
int A[1200000];
pair<int,int> p[1200000];
int hsh[1200000];
int hshS[1200000];
void add(int x,int val)
{
    while(x<=n)
    {
        hsh[x]+=val;
        x+=x&(-x);
    }
}
void addS(int x,int val)
{
    while(x<=n)
    {
        hshS[x]+=val;
        x+=x&(-x);
    }
}
int sum(int x)
{
    int ss=0;
    while(x>0)
    {
        ss+=hsh[x];
        x-=x&(-x);
    }

    return ss;
}
int sumS(int x)
{
    int ss=0;
    while(x>0)
    {
        ss+=hshS[x];
        x-=x&(-x);
    }

    return ss;
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        p[i]=make_pair(a,b);
       // A[a]=b;
    }
    sort(&p[1],&p[n+1]);
    for(i=1;i<=n;i++)
    {
        A[i]=p[i].second;
        //printf("%d ",A[i]);
    }
    //printf("\n");
    int cot=0;
    for(i=n;i>=1;i--)
    {
        cot+=sumS(A[i])+p[i].X*sum(A[i]);
        //cot+=sum(A[i]);
        add(A[i],1);
        addS(A[i],p[i].X);
    }
    printf("%d",cot);
}
