#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
string str[1000005];
int len[1000005];
int hsh[12];
map<pair<int,int>,bool> con;
vector<int> hshI[10000005];
int main()
{
    int n,i,j,k;
    cin >> n;
    for(j=0;j<n;j++)
    {
        cin >> str[j];
        len[j]=str[j].size();
        set<int> jum;
        set<int>::iterator it;
        for(i=0;i<len[j];i++)
        {
            jum.insert(str[j][i]-'0');
        }
        for(it=jum.begin();it!=jum.end();it++)
        {
            //hshI[j][*it]++;
            hshI[j].push_back(*it);
            hsh[*it]++;
        }
        jum.clear();
    }
    int sum=0;
   // printf("=%d\n",hshI[0][6]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<hshI[i].size();j++)
        {
            sum+=hsh[hshI[i][j]]-1;
                //hshI[i][str[i][j]-'0']--;
            /*for(k=0;k<=9;k++)
            {
                if(hshI[i][k]>=1)
                    hshI[i][k]--;
            }*/

        }
    }
    printf("%d\n",sum);
}
