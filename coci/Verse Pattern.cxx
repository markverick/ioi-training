#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char str[135];
string s;
int b[135],a[135],hsh[500];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,len;
	hsh['a']=1;
	hsh['e']=1;
	hsh['i']=1;
	hsh['o']=1;
	hsh['u']=1;
	hsh['y']=1;
	gets(str);
	sscanf(str,"%d",&n);
	gets(str);
	len=strlen(str);
	str[len++]=' ';
	j=1;
	for(i=0;i<len;i++)
    {
        if(str[i]==' ')
        {
            sscanf(&s[0],"%d",&a[j]);
            j++;
            s.clear();
            continue;
        }
        s.push_back(str[i]);
    }
    for(i=1;i<=n;i++)
    {
        gets(str);
        len=strlen(str);
        for(j=0;j<len;j++)
        {
            if(hsh[str[j]])
                b[i]++;
        }
        if(a[i]!=b[i])
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}
