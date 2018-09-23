#include<bits/stdc++.h>
#define MI 1000000000
#define M 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int hsh[50000],A[50000],B[50000];
vector<int> v;
unordered_map<int,int> ha,hb;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,m,a,b;
	vector<int> sa,sb;
	for(i=2;i<=40000;i++)
    {
        if(hsh[i]==0)
        {
            v.emplace_back(i);
            for(j=i;j<=33000;j+=i)
                hsh[j]=1;
        }
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(j=0;j<v.size();j++)
        {
            if(v[j]>sqrt(a)+1)
                break;
            while(a%v[j]==0)
            {
                A[j]++;
                a/=v[j];
            }
        }
        if(a>1) for(j=0;j<v.size();j++)
        {
            if(v[j]==a)
            {
                A[j]++;
                a=0;
                break;
            }
        }
        if(a>1)
            sa.emplace_back(a);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&b);
        for(j=0;j<v.size();j++)
        {
            if(v[j]>sqrt(b)+1)
                break;
            while(b%v[j]==0)
            {
                B[j]++;
                b/=v[j];
            }
        }
        if(b>1) for(j=0;j<v.size();j++)
        {
            if(v[j]==b)
            {
                B[j]++;
                b=0;
                break;
            }
        }
        if(b>1)
            sb.emplace_back(b);
    }
    long long sum=1;
    int fk=0;
    for(i=0;i<v.size();i++)
    {
        for(j=0;j<min(A[i],B[i]);j++)
        {
            sum*=(long long)v[i];
            if(sum>=M)
                fk=1;
            sum%=M;
        }
    }
    for(i=0;i<sa.size();i++)
    {
        ha[sa[i]]++;
    }
    for(i=0;i<sb.size();i++)
    {
        for(j=0;j<ha[sb[i]];j++)
        {
            sum*=(long long)sb[i];
            if(sum>=M)
                fk=1;
            sum%=M;
        }
    }
    if(fk)
        printf("%09lld",sum);
    else
        printf("%lld",sum);

}
