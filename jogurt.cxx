#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int L[70000],R[70000],a[70000];
void dfs(int idx)
{
    if(idx==0)
        return;
//    printf("!%d\n",idx);
    printf("%d ",a[idx]);
    dfs(L[idx]);
    dfs(R[idx]);
}
int main()
{
	int i,j=0,k,n,p;
	scanf("%d",&n);
	a[1]=1;
	p=1;
    for(i=1;i<n;p=(p+1)*2-1,i++)
    {
        for(j=1;j<=p;j++)
        {
            a[j]*=2;
            a[p+j]=a[j];
            if(L[j])
                L[p+j]=L[j]+p;
            if(R[j])
                R[p+j]=R[j]+p;
        }
        a[p*2+1]=1;
        L[p*2+1]=p;
        R[p*2+1]=p*2;
        for(j=1;j<=p;j++)
        {
            if(L[j]==0&&R[j]==0)
                a[j]++;
            if(L[p+j]&&R[p+j])
                a[p+j]++;
        }
    }
//    for(i=1;i<=p;i++)
//    {
//        printf("%d < %d > %d\n",L[i],i,R[i]);
//    }
    dfs(p);
}
