#include<bits/stdc++.h>
using namespace std;
vector<int> PrefixFunction(string S) {
    vector<int> p(S.size());
    int j = 0;
    for (int i = 1; i < (int)S.size(); i++) {
        while (j > 0 && S[j] != S[i])
            j = p[j-1];

        if (S[j] == S[i])
            j++;
        p[i] = j;
    }
    return p;
}
string s;
vector<int> v;
int main()
{
    int i;
    cin >> s;
    v=PrefixFunction(s);
    for(i=0;i<v.size();i++)
    {
        printf("%d ",v[i]);
    }
}
