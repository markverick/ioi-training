#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
string a[2510],b[2510];
int x[2510],y[2510];
map<string,int> mp;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        if(mp.find(a[i])==mp.end())
            mp[a[i]]=i;
        x[i]=mp[a[i]];
    }
    for(i=1;i<=n;i++)
    {
        cin >> b[i];
        y[i]=mp[b[i]];
    }
    int cot=0;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(y[j]==0||y[i]==0)
                continue;
            if(y[j]>y[i])
                cot++;
        }
    }
    printf("%d/%d",cot,n*(n-1)/2);
}
