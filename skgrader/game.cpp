#include<bits/stdc++.h>
using namespace std;

string name[12000];
int in[12000];
map<string,int> score;
map<string,int> hsh;
int scoreIdx[12000];
int main()
{
    int n;
    cin >> n;
    int i,j;
    string f;
    for(i=0;i<n;i++)
    {
        cin >> f;
    }
    int m;
    cin >> m;
    for(i=0;i<m;i++)
    {
        cin >> name[i] >> in[i];
        score[name[i]]+=in[i];
        scoreIdx[i]=score[name[i]];

    }
    int k;
    scanf("%d",&k);
    for(i=0;i<m;i++)
    {
        if(score[name[i]]>=k)
        {
            hsh[name[i]]=1;
        }
    }
    for(i=0;i<m;i++)
    {
        if(scoreIdx[i]>=k&&hsh[name[i]]==1)
        {
            cout << name[i];
            exit(0);
        }
    }
}
