#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define X first
#define Y second
using namespace std;
char sA[120];
char sB[120];
int hsh[520];
vector<char> v;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,T,i,j,k;
    int lA,lB,times;
    double prob;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d",lA,lB,times);
        scanf("%s %s",sA,sB);
        for(i=0;i<lA;i++)
        {
            if(hsh[sA[i]]==0)
                v.PB(sA[i]);
            hsh[sA[i]]++;
            if(hsh[sA[i]])
        }
        prob=1.0;
        for(i=0;i<v.size();i++)
        {
            prob*=hsh[v[i]]/sA
        }
    }
}

