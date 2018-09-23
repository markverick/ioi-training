#include<bits/stdc++.h>
#define MP(x,y) make_pair(x,y)
using namespace std;
int n;
pair<int,int> v[12];
int vert[2200][2200];
int hsh[12];
int dp(int idx,int cot,char dir)
{
    //  printf("%d %d\n",idx,cot);
    int poss=0;
    int i,j;
    if(cot==n-1)
    {
        //printf("F");
        if(dir=='r')
        {
            if(v[idx].first==1000)
                return 1;
            if(v[idx].second==1000&&v[idx].first>=1000)
                return 1;
            return 0;
        }
        if(dir=='l')
        {
            if(v[idx].first==1000)
                return 1;
            if(v[idx].second==1000&&v[idx].first<=1000)
                return 1;
            return 0;
        }
        if(dir=='u')
        {
            if(v[idx].second==1000)
                return 1;
            if(v[idx].first==1000&&v[idx].second<=1000)
                return 1;
            return 0;
        }
        if(dir=='d')
        {
            if(v[idx].second==1000)
                return 1;
            if(v[idx].first==1000&&v[idx].second>=1000)
                return 1;
            return 0;
        }
        return 0;
    }
    hsh[idx]=1;
    for(i=v[idx].first+1;dir!='r'&&i<2001;i++)
    {
        if(vert[i][v[idx].second]>=0&&hsh[vert[i][v[idx].second]]==0)
        {
            poss=max(poss,dp(vert[i][v[idx].second],cot+1,'r'));
        }
    }
    for(i=v[idx].first-1;dir!='l'&&i>=0;i--)
    {
        if(vert[i][v[idx].second]>=0&&hsh[vert[i][v[idx].second]]==0)
        {
            poss=max(poss,dp(vert[i][v[idx].second],cot+1,'l'));
        }
    }
    for(i=v[idx].second+1;dir!='d'&&i<2001;i++)
    {
        if(vert[v[idx].first][i]>=0&&hsh[vert[v[idx].first][i]]==0)
        {
            poss=max(poss,dp(vert[v[idx].first][i],cot+1,'d'));
        }
    }
    for(i=v[idx].second-1;dir!='u'&&i>=0;i--)
    {
        if(vert[v[idx].first][i]>=0&&hsh[vert[v[idx].first][i]]==0)
        {
            poss=max(poss,dp(vert[v[idx].first][i],cot+1,'u'));
        }
    }
    hsh[idx]=0;
    //printf("%d",poss);
    return poss;
}
int main()
{
    scanf("%d",&n);
    memset(vert,-1,sizeof vert);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        a+=1000;
        b+=1000;
        vert[a][b]=i;
        v[i]=MP(a,b);
    }
    int cot=0;
    for(i=0;i<n;i++)
    {
        if(v[i].first==1000||v[i].second==1000)
        {
            //printf("FFF");
            memset(hsh,0,sizeof hsh);
            cot+=dp(i,0,'f');
        }

    }
    printf("%d",cot);
}
