#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> v[12];
vector<int>::iterator it;
char s[500135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,L,R,N;
	scanf("%d %d",&n,&m);
	N=n-m;
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
    {
        v[s[i]-'0'].emplace_back(i);
    }
    L=1;
    string s;
    for(i=N;i>=1;i--)
    {
        R=n-i+1;
        for(j=9;j>=0;j--)
        {

            it=lower_bound(v[j].begin(),v[j].end(),L);
            if(it==v[j].end())continue;
            if(*it<=R)
            {
                break;
            }
        }
        L=*it+1;
        s.push_back('0'+j);
    }
    cout << s;
}
