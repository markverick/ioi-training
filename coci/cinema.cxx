#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[55];
vector<int> v;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	scanf("%d %s",&n,s);
	v.emplace_back(0);
	for(i=0;i<n;i++)
    {
        if(s[i]=='S')
            v.emplace_back(1);
        else
        {
            i++;
            v.emplace_back(1);
            v.emplace_back(1);
        }
        v.emplace_back(0);
    }
    int cot=0;
    for(i=1;i<v.size()-1;i++)
    {
        if(v[i])
        {
            if(v[i-1]==0)
                v[i-1]=1,cot++;
            else if(v[i+1]==0)
                v[i+1]=1,cot++;
        }
    }
    printf("%d",cot);
}
