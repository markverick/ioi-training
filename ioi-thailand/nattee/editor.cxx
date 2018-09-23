#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
list<string> ls;
list<string> ::iterator it;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	string ch,s;
	cin >> n;
	it=ls.begin();
	while(n--)
    {
        cin >> ch;
        switch (ch[0])
        {
        case 'i':
            cin >> s;
            ls.insert(it,s);
            break;
        case 'r':
            if(it!=ls.end())
                it++;break;
        case 'l':
            if(it!=ls.begin())
                it--;break;
        case 'd':
            if(it!=ls.end())
                it=ls.erase(it);
            break;
        case 'b':
            if(it!=ls.begin())
            {
                it--;
                it=ls.erase(it);
            }
        }
    }
    for(it=ls.begin();it!=ls.end();it++)
    {
        cout << *it << " ";
    }
}
