#include<bits/stdc++.h>
#define MI 100000000000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m,a[8][8],heat[8][8],hsh[8];
long long jum[1800000];
long long dp(int bit,int x)
{
    if(jum[bit]<=MI)
        return jum[bit];
    if(x==1)
    {
        return 0;
    }
//    printf("%d\n",bit);
    int ar[8],i,j,k=bit,bt;
    long long mn=MI;
    for(i=0;i<n;i++)
    {
        ar[i]=k%m;
//        printf("%d ",ar[i]);
        k/=m;
    }
//    printf("\n");
//    system("pause");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            bt=0;
            ar[i]--;ar[j]--;
            if(ar[i]<0||ar[j]<0||ar[a[i][j]]>=m)
            {
                ar[i]++;ar[j]++;
                continue;
            }
            ar[a[i][j]]++;
            for(k=n-1;k>=0;k--)
            {
                bt*=m;
                bt+=ar[k];
            }
            ar[i]++;ar[j]++;ar[a[i][j]]--;
            mn=min(mn,dp(bt,x-1)+heat[i][j]);
        }
    }
    return jum[bit]=mn;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,T;
	scanf("%d",&T);
	while(T--)
    {
        for(i=0;i<=1790000;i++)
            jum[i]=MI+1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d %d",&a[i][j],&heat[i][j]);
                a[i][j]--;
            }
        }
        scanf("%d",&m);
        memset(hsh,0,sizeof hsh);
        for(i=0;i<m;i++)
        {
            scanf("%d",&k);
            hsh[k-1]++;
        }
        k=0;
        m++;
        for(i=n-1;i>=0;i--)
        {
            k*=m;
            k+=hsh[i];
        }
        printf("%lld\n",dp(k,m-1));
        scanf("%*s");
    }
}
