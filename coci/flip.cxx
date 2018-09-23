#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,k,x=0,y=0;
	string a,b;
    cin >> a>>b;
    for(i=a.size()-1;i>=0;i--)
        x=x*10+a[i]-'0';
    for(i=b.size()-1;i>=0;i--)
        y=y*10+b[i]-'0';
    printf("%d",max(x,y));
}
