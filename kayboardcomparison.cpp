#include<bits/stdc++.h>
#define MP make_pair
using namespace std;

string q[6];
string d[6];
string str;
map<char,pair<int,int> > pos1;
map<char,pair<int,int> > pos2;

int main()
{
    int n;
    q[1]="`1234567890-=";
    q[2]=" qwertyuiop[]\\";
    q[3]=" asdfghjkl;\'";
    q[4]=" zxcvbnm,./";

    d[1]="`123qjlmfp/[]";
    d[2]=" 456.orsuyb;=\\";
    d[3]=" 789aehtddck-";
    d[4]=" 0zx,inwvg\'";
    int i,j,k;
    for(i=1;i<=4;i++)
    {
        for(j=0;j<13;j++)
        {
            pos1[q[i][j]]=MP(i,j);
            if(q[i][j]>='a'&&q[i][j]<='z')
                pos1[q[i][j]-'a'+'A']=MP(i,j);
        }
    }
    for(i=1;i<=4;i++)
    {
        for(j=0;j<13;j++)
        {
            pos2[q[i][j]]=MP(i,j);
            if(d[i][j]>='a'&&d[i][j]<='z')
                pos2[d[i][j]-'a'+'A']=MP(i,j);
        }
    }
    /*for(char c='A';c<='Z';c++)
    {
        printf("%d %d\n",pos2[c].first,pos2[c].second);
    }*/

    while(cin >> str)
    {
        int len=str.size();
        int s1=0;
        int s2=0;
        int s3=0;
        for(i=0;i<len;i++)
        {
            int mi=10000000;

        }
    }

}
