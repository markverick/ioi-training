#include<bits/stdc++.h>
using namespace std;
char str[135];
int mat[135][135],state[135],result[135],mn,ck;
void dfs(int idx,int cot,int mn,int app)
{
    int i;
    state[idx]=1;
    if(idx==37)
    {
        for(i=1;i<cot;i++)
        {
            mat[result[i-1]][result[i]]-=mn;
            mat[result[i]][result[i-1]]+=mn;
        }
        ck=1;
        return;
    }
    for(i=0;i<=37;i++)
    {
        if(state[i]==0&&mat[idx][i]>0)
        {
            result[cot]=i;
            dfs(i,cot+1,min(mn,mat[idx][i]));
        }
    }
}
int main()
{
    int i,j,k;
    while(135)
    {
        memset(mat,0,sizeof mat);
        while(135)
        {
            if(gets(str)==0)
                return 0;
            if(str[0]=='\0')
                break;
            mat[0][str[0]-'A'+1]=str[1]-'0';
            for(i=3;str[i]!=';';i++)
            {
                mat[str[0]-'A'+1][26+str[i]-'0'+1]++;
                mat[26+str[i]-'0'+1][37]++;
            }
        }
        ck=1;
        int sum=0;
        while(ck==1)
        {
            ck=0;
            memset(state,0,sizeof state);
            dfs(0,1,135);
        }
        for(i=27;i<=36;i++)
        {
            sum+=mat[37][i];
        }
        printf("%d\n",sum);
    }
}
