#include<bits/stdc++.h>
using namespace std;
map<string,int> name;
map<string,int>::iterator it;
int main()
{
    int n;
    int i,j;
    string a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        cin >> a;
        if(i==0){name[a]++;b=a;}
        else
        name[a]++;
    }
    for(i=0;i<n-1;i++)
    {
        cin >> a;
        name[a]--;
    }
    for(it=name.begin();it!=name.end();it++)
    {
        //cout << (*it).second;
        if((*it).second!=0)
        {
            cout << (*it).first;
        }
    }
}
