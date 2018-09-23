#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[111],hsh[1000135],all[80000],pm[1000135];
vector<int> primes;
char v[105][80000];
int Pow(int b,int p)
{
    if(p==0)
        return 1;
    int tmp=Pow(b,p/2);
    tmp*=tmp;
    if(p%2)
        tmp*=b;
    return tmp;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
    scanf("%d",&n);
    for(i=2;i<=1000000;i++)
    {
        if(hsh[i]==0)
        {
            pm[i]=primes.size();
            primes.emplace_back(i);
            for(j=i;j<=1000000;j+=i)
                hsh[j]=1;
        }
    }
//    printf("%d\n",primes.size());
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        k=a[i];
        for(j=0;j<primes.size();j++)
        {
            if(primes[j]>sqrt(k)+0.00001)
                break;
            while(k%primes[j]==0)
            {
                v[i][j]++;
                all[j]++;
                k/=primes[j];
            }
        }
        if(k>1)
        {
            v[i][pm[k]]++;
            all[pm[k]]++;
        }
    }
    int prod=1;
    for(i=0;i<primes.size();i++)
    {
        prod*=pow(primes[i],all[i]/n);
    }
    printf("%d ",prod);
    int sum=0;
    for(i=0;i<primes.size();i++)
    {
        for(j=1;j<=n;j++)
        {
            sum+=max(0,all[i]/n-v[j][i]);
        }
    }
    printf("%d",sum);
}
