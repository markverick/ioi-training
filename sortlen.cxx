#include<bits/stdc++.h>
using namespace std;
string s[1135],str;
int main()
{
    int i,j,k;
    cin >> str;
    s[str.size()-1]=str[str.size()-1];
    for(i=str.size()-2;i>=0;i--)
    {
        s[i]=str[i]+s[i+1];
    }
    sort(&s[0],&s[str.size()]);
    for(i=0;i<str.size();i++)
    {
        cout << s[i] << "\n";
    }
}
