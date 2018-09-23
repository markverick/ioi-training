#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char s[200135];
vector<int> t;
int freq[14][200135];
vector<pair<int,int> > hsh[200135];
int main()
{
    int i,j,k,a,b,n,len,sum=0;
    scanf("%d %d %d",&a,&b,&n);
    while(scanf("%s",s)!=EOF)
    {
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            t.emplace_back(s[i]-'0');
        }
    }
    for(len=a;len<=b;len++)
    {
        sum=0;
        for(i=0;i<t.size();i++)
        {
            sum*=2;
            sum+=t[i];
            if(i>=len)
            {
                sum-=t[i-len]*(1<<len);
            }
            if(i+1>=len)
                freq[len][sum]++;
        }
    }
    for(i=a;i<=b;i++)
    {
        for(j=0;j<=10000;j++)
        {
            hsh[freq[i][j]].emplace_back(j,i);
        }
    }
    int cot=0,x;
    stack<int> st;
    for(i=t.size();i>=1;i--)
    {
        if(hsh[i].empty())
            continue;
        printf("%d\n",i);
        for(j=0;j<hsh[i].size();j++)
        {
            tie(x,len)=hsh[i][j];
            while(x>0)
            {
                st.emplace(x%2);
                x/=2;
                len--;
            }
            while(len--)
            {
                st.emplace(0);
            }
            while(!st.empty())
            {
                printf("%d",st.top());
                st.pop();
            }
            printf(" ");
        }
        printf("\n");
        cot++;
        if(cot>=n)
            break;
    }
}
