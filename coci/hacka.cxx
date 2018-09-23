#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int t[10000000];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	string a;
	cin >> n >> a;
	int q=(a[0]-'0')*10+(a[1]-'0');
	if(n==12 and q>12 and q%10 ==0)
        q=10;
    else
    {
        if((n==24 and q>=24) or (n==12 and q>12))
            q%=10;
        if(n==12 and q==0)
            q++;
    }
    cout <<q/10 << q%10<<":";
    int w=(a[3]-'0')*10+(a[4]-'0');
    w%=60;
    cout <<w/10<<w%10<<endl;
}
