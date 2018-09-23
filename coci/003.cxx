#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
#define PB push_back
using namespace std;
string maps[6];
char s[20];
int main()
{
    int i,j,k,n;
    maps[1].push_back('.');
    maps[2].push_back('.');
    maps[3].push_back('#');
    scanf("%s",s+1);
    n=strlen(s+1);
    for(i=1;i<=n;i++)
    {
        if(i%3!=0)
        {
            maps[1]+=".#..";
            maps[2]+="#.#.";
            maps[3]+=".";
            maps[3]+=s[i];
            maps[3]+=".#";
        }
        else
        {
            maps[1]+=".*..";
            maps[2]+="*.*.";
            maps[3][maps[3].size()-1]='*';
            maps[3]+=".";
            maps[3]+=s[i];
            maps[3]+=".*";
        }
    }
    maps[4]=maps[2];
    maps[5]=maps[1];
    for(i=1;i<=5;i++)
    {
        cout << maps[i]<<"\n";
    }
}
