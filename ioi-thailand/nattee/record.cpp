#include<bits/stdc++.h>
using namespace std;
map<string,int> hsh;
string a[5],s;
int main()
{
	int i,j,k,n,mc=0;
	cin >> n;
	for(i=1;i<=n;i++)
    {
        cin >> a[0]>>a[1]>>a[2];
        sort(&a[0],&a[3]);
        s=a[0]+a[1]+a[2];
        hsh[s]++;
        mc=max(mc,hsh[s]);
    }
    printf("%d",mc);
}
