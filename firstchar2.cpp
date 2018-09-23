#include<bits/stdc++.h>
using namespace std;
set<string> name;
set<string> ::iterator it,it2;
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        string in;
        cin >> in;
        for(j=5;j<in.size();j++)
        {
            in[j]='\0';
        }

        name.insert(in);
    }
    for(it=name.begin();it!=name.end();it++)
    {
        cout << *it <<'\n';
    }
}
