#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[1000135];
stack<char> st;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
    int n,i,j,k,len,cot=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        for(j=0;j<len;j++)
        {
            if(st.empty()||st.top()!=s[j])
                st.emplace(s[j]);
            else
                st.pop();
        }
        if(st.empty())
           cot++;
        while(!st.empty())
            st.pop();
    }
    printf("%d",cot);
}
