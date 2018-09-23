#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin >> s;
    for(i=0;i<s.size();i++)
        yo[0][i]=s[i];
    for(st=1,i=1;i >> 1 <s.size();i<<=1,st++)
    {
        for(j=0;j<s.size();j++)
        {
            get<0>(a[j])=yo[st-1][j];
            get<1>(a[j])=j+i<s.size() ? yo[st-1][j+i] : -1;
            get<2>(a[j])=j;
        }
        sort(&a[0],&a[s.size()]);
        for(j=0;j<s.size();j++)
            yo[st][get<2>(a[j])]= j>0 && get<0>(a[j])==get<0>(a[j-1]) && get<1>(a[j])==get<1>(a[j-1]) ? yo[st][get<2>(a[j-1])] : j;
    }
}
