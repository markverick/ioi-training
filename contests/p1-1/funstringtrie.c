#include<bits/stdc++.h>
using namespace std;
int n;
string str[3135];
int len[3135],s;
char tree[1000005];
int state[1000005];
int teema[1000005];
int dp[1000005];
int go[1000005][21],T;
int sp[1000005][21];
long long fac[1000005];
long long inv[1000005];
int leaf[1000005];
long long cot=1;
vector<int> v,hi;
void append(int i,int idx)
{
//    printf("%c\n",tree[idx]);
    if(i==str[s].size())
    {
        leaf[s]=idx;
        tree[idx]='0';
        return;
    }
    if(go[idx][str[s][i]-'A']==0)
    {
        go[idx][str[s][i]-'A']=T;
        tree[T++]=str[s][i];
        append(i+1,T-1);
    }
    else
    {
        append(i+1,go[idx][str[s][i]-'A']);
    }
    return;
}
int mic(int idx)
{
//    state[idx]=1;
    if(tree[idx]=='0')
    {
        return 1;
    }
    int i;
    long long sum=1;
    int m=0;
    for(i=0;i<26;i++)
    {
        if(go[idx][i]>0)
        {
            m++;
//            if(state[go[idx][i]])
//                continue;
            sum*=mic(go[idx][i]);
        }
    }
    sum*=fac[m];
    sum%=1000000007;
    return sum;
}
int main()
{
    int i,j,k;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> str[i];
    }
    sort(&str[1],&str[n+1]);
//    for(i=1;i<=n;i++)
//    {
//        cout << str[i] << "\n";
//    }
    T=2;
    for(i=1;i<=n;i++)
    {
        s=i;
        append(0,1);
    }
    memset(state,0,sizeof state);
    fac[0]=1;
    fac[1]=1;
    for(i=2;i<=1000000;i++)
        fac[i]=fac[i-1]*i,fac[i]%=1000000007;
    printf("%d\n",mic(1));
}
