#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[100];
map<string,int> mp;
string str[111];
int toint(string s)
{
    int i,j;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='I'||s[i]=='V')
        {
            j=i;
            break;
        }
    }
    string a,b;
    for(i=0;i<j;i++)
    {
        a.push_back(s[i]);
    }
    for(i=j;i<s.size();i++)
    {
        b.push_back(s[i]);
    }
    if(b.empty())
        return 1000000000;
    if(!a.empty()&&mp.find(a)!=mp.end()&&mp.find(b)!=mp.end())
        return mp[a]+mp[b];
    else if(a.empty()&&mp.find(b)!=mp.end())
        return mp[b];
    return 1000000000;
//    cout << a << "-" <<b << "\n";
}
string tostr(int x)
{
    string s;
    return str[(x/10)*10]+str[x%10];
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,len;
	str[1]="I";
	str[2]="II";
	str[3]="III";
	str[4]="IV";
	str[5]="V";
	str[6]="VI";
	str[7]="VII";
	str[8]="VIII";
	str[9]="IX";
	str[10]="X";
	str[20]="XX";
	str[30]="XXX";
	str[40]="XL";
	str[50]="L";
	str[60]="LX";
	str[70]="LXX";
	str[80]="LXXX";
	str[90]="XC";
	for(i=1;i<100;i++)
    {
        if(!str[i].empty())
            mp[str[i]]=i;
    }
	string s;
	cin >> s;
	sort(s.begin(),s.end());
	int mn=1000000000;
	do
    {
//        cout << s <<" "<< toint(s) << "\n";
        mn=min(mn,toint(s));
    }
    while(next_permutation(s.begin(),s.end()));
//    printf("%d",mn);
    cout << tostr(mn);
}
