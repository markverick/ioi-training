#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long n,m,bd,a[1531],hsh[1531];
vector<long long> st;
vector<long long> Pow(long long p)
{
    if(p==1)
        return st;
    vector<long long> u=Pow(p/2),v;
    long long i,j;
    for(i=0;i<m;i++)
        v.emplace_back(0);
    for(i=0;i<m;i++)
    {
        if(!u[i])continue;
        for(j=0;j<m;j++)
        {
            if(!u[j])continue;
            v[(i*j)%m]=1;
        }
    }
    if(p%2)
    {
        u=v;
        for(i=0;i<m;i++)
            v[i]=0;
        for(i=0;i<m;i++)
        {
            if(!u[i])continue;
            for(j=0;j<m;j++)
            {
                if(!st[j])continue;
                v[(i*j)%m]=1;
            }
        }
    }
    return v;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k;
	scanf("%lld %lld %lld",&bd,&m,&n);
	for(i=0;i<n;i++)
        scanf("%lld",&a[i]),hsh[a[i]]++;
    for(i=0;i<m;i++)
    {
        if(hsh[i])
            st.emplace_back(1);
        else
            st.emplace_back(0);
    }
    vector<long long> v=Pow(bd);
    for(i=0;i<v.size();i++)
        if(v[i])printf("%lld ",i);
}
