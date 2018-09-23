#include<bits/stdc++.h>
using namespace std;
int n;
string str[3005];
long long fac[3135];
int dfs(int fst,int lst,int idx)
{
    if(fst==lst)
        return 1;
    int i,blk=1,x=fst;
    long long cot=1;
    for(i=fst+1;i<=lst;i++)
    {
        if(idx>=str[i-1].size()&&idx>=str[i].size())
            continue;
        if((idx>=str[i-1].size()&&idx<str[i].size())||(idx>=str[i].size()&&idx<str[i-1].size())||(str[i-1][idx]!=str[i][idx]))
        {
            cot*=dfs(x,i-1,idx+1);
            cot%=1000000007;
            x=i;
            blk++;
        }
    }
    cot*=dfs(x,lst,idx+1);
    cot%=1000000007;
    cot*=fac[blk];
    cot%=1000000007;
    return (int)cot;
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
    fac[0]=1;fac[1]=1;
    for(i=2;i<=3005;i++)
        fac[i]=fac[i-1]*i,fac[i]%=1000000007;
    printf("%d\n",dfs(1,n,0));
//    for(i=1;i<=n;i++)
//    {
//        cout << str[i]<<"\n";
//    }
}
