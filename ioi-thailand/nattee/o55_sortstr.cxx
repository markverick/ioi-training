#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> p;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a;
	cin >> n;
	for(i=0;i<n;i++)
	{
	    cin >> a;
	    p.emplace_back(a);
	}
	sort(p.begin(),p.end());
	for(i=0;i<n;i++)
        cout << p[i]<< "\n";
}
