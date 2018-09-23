#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char a[2135],b[2135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int la,lb,i,j,k,st=0,l;
	string s;
	char ch;
	scanf("%s %s",a,b);
	la=strlen(a);
	a[la++]=',';
	lb=strlen(b);
	b[lb++]=',';
	j=0;
	for(i=0;i<la;i++)
    {
        if(a[i]>='A'&&a[i]<='Z')
        {
            ch=a[i+1];
            k=j;
            st=0;
            while(st||b[k]!=ch)
            {
                if(b[k]=='(')st++;
                if(!st&&(b[k]<'0'||b[k]>'9'))
                {
                    printf("no");return 0;
                }
                if(b[k]==')')st--;
                k++;
            }
            for(l=j;l<k;l++)
                s.push_back(b[l]);
            s.push_back('\n');
            j=k;
        }
        else
        {
            if(a[i]!=b[j])
            {
                printf("no");
                return 0;
            }
            j++;
        }
    }
    cout << s;
}
