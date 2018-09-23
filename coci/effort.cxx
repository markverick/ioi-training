#include<bits/stdc++.h>
using namespace std;
char s[135];
vector<string> v;
bool cmp(string a,string b)
{
    if(a.size()==b.size())
    {
        return a<b;
    }
    return a.size()<b.size();
}
int main()
{
	int i,j,k,n,l,len;
	string a;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        memset(s,0,sizeof s);
        scanf("%s",s+1);
        len=strlen(s+1);
        k=0;
        for(j=1;j<=len;j++)
        {
            if(s[j]>='0'&&s[j]<='9')
            {
                a.clear();
                while(s[j]=='0')
                    j++;
                for(j=j;j<=len;j++)
                {
                    if(s[j]<'0'||s[j]>'9')
                        break;
                    a.push_back(s[j]);
                }
                if(a.empty())
                    a.push_back('0');
                v.emplace_back(a);
                j--;
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(i=0;i<v.size();i++)
        cout << v[i] << "\n";
}
