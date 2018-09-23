#include<bits/stdc++.h>
using namespace std;
string str[5];
unordered_map<string,int> hsh;
int main()
{
    int n,i,j,mc=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=3;j++)
        {
            cin >> str[j];
        }
        sort(&str[1],&str[4]);
        hsh[str[1]+str[2]+str[3]]++;
        mc=max(mc,hsh[str[1]+str[2]+str[3]]);
    }
    printf("%d",mc);
}
