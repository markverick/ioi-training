#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
string str[22],s[1135],d[12],t[12];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,sum=0;
	s[1]="one"; s[2]="two"; s[3]="three"; s[4]="four"; s[5]="five"; s[6]="six"; s[7]="seven"; s[8]="eight"; s[9]="nine"; s[10]="ten";
	s[11]="eleven"; s[12]="twelve"; s[13]="thirteen"; s[14]="fourteen"; s[15]="fifteen"; s[16]="sixteen"; s[17]="seventeen"; s[18]="eighteen"; s[19]="nineteen";
	d[2]="twenty"; d[3]="thirty"; d[4]="forty"; d[5]="fifty"; d[6]="sixty"; d[7]="seventy"; d[8]="eighty"; d[9]="ninety"; 
	t[1]="onehundred"; t[2]="twohundred"; t[3]="threehundred"; t[4]="fourhundred"; t[5]="fivehundred"; t[6]="sixhundred"; t[7]="sevenhundred"; t[8]="eighthundred"; t[9]="ninehundred";

	for(i=20;i<=99;i++)
		s[i]=d[i/10]+s[i%10];
	for(i=100;i<=999;i++)
		s[i]=t[i/100]+s[i%100];
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> str[i];
		if(str[i][0]!='$')
			sum+=str[i].size();
	}
	for(i=1;i<=999;i++)
	{
		if(sum+s[i].size()==i)
		{
			for(j=1;j<=n;j++)
			{
				if(str[j][0]!='$')
					cout << str[j];
				else
					cout << s[i];
				cout << " ";
			}
			return 0;
		}
	}
}