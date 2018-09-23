#include<bits/stdc++.h>
using namespace std;
map<string,int> hsh;
int main()
{
    int i,j,k,n,cot=0;
    string s;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> s;
        if(hsh[s]>i-1-hsh[s])
            cot++;
        hsh[s]++;
    }
    printf("%d",cot);
}
