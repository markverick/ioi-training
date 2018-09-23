#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135],ft[100135],n;
long long cot=0;
void rev(int fst,int lst)
{
    int x=(lst-fst)/2;
    for(int i=0;i<=x;i++)
        swap(a[fst+i],a[lst-i]);
}
void add(int x,int val)
{
    while(x<=n)
    {
        ft[x]+=val;
        x+=x&-x;
    }
}
int sum(int x)
{
    int sm=0;
    while(x>0)
    {
        sm+=ft[x];
        x-=x&-x;
    }
    return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    j=1;
    for(i=2;i<=n;i++)
    {
        if(a[i]>=a[i-1])
        {
            if(j!=i-1)
            {
                rev(j,i-1);
                cot++;
            }
            j=i;
        }
    }
    if(j!=n)
        rev(j,n),cot++;
//    printf("%lld\n",cot);
    for(i=1;i<=n;i++)
    {
        cot+=i-sum(a[i])-1;
//        printf("%d %lld\n",i,cot);
        add(a[i],1);
    }
    printf("%lld",cot);
}
