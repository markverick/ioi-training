#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[111];
int hsh[555];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	hsh['C']=1;
	hsh['A']=1;
	hsh['M']=1;
	hsh['B']=1;
	hsh['R']=1;
	hsh['I']=1;
	hsh['D']=1;
	hsh['G']=1;
	hsh['E']=1;
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++)
    {
        if(hsh[s[i]]==0)
            printf("%c",s[i]);
    }
}
