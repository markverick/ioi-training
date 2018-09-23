#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char str[100135];
int main()
{
	freopen("out.txt","w",stdout);
	freopen("vocab.txt","r",stdin);
	int n,i,j,k;
	while(gets(str))
    {
        if(str[0]=='a'&&str[1]=='n'&&str[2]=='t')
            printf("; %s",str);
        else
            printf("%s\n");
    }
}
