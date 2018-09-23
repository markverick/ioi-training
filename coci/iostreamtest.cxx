#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	char omelet,*p;
	cin >> omelet;
	p=&omelet;
	cout << p << "\n";
//	system("pause");
	for(p=&omelet;*p;p++)
        cout << *p << " " << p << "\n";
    p=&omelet;
	cout << p;
}
