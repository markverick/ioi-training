#include<bits/stdc++.h>
using namespace std;
int maps[7][7];
int start[5],req[5];
vector<int> vemp,vst,v;
string semp,str;
queue<pair<vector<int>,string> > q;
map<vector<int>,int> hsh;
int main()
{
    int i,j,k,fu,T,cot=0,yay=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&maps[i][j]);
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        while(!q.empty())
            q.pop();
        hsh.clear();
        vst.clear();
        for(i=0;i<3;i++)
        {
            scanf("%d",&start[i]);
            vst.emplace_back(start[i]);
        }
        for(i=0;i<3;i++)
            scanf("%d",&req[i]);
        q.emplace(vst,semp);
        cot=0;yay=0;
        while(cot<=10000&&!q.empty())
        {
            cot++;
            tie(v,str)=q.front();
            q.pop();fu=0;
            for(i=0;i<3;i++)
            {
                //printf("%d ",v[i]);
                if(req[i]==v[i])
                    fu++;
            }
            //cout << "\n" << str << "\n";
            if(fu==3)
            {
                printf("%d ",str.size());
                for(i=0;i<str.size();i++)
                {
                    printf("%c",str[i]);
                }
                yay=1;
                printf("\n");
                break;
            }
            str.push_back(3);
            for(i=0;i<3;i++)
            {
                if(v[i]>0)
                {
                    str[str.size()-1]='A'+i;
                    v[i]--;
                    for(j=0;j<3;j++)
                        v[j]+=maps[i][j];
                    if(hsh.find(v)==hsh.end())
                    {
                        hsh[v]=1;
                        q.emplace(v,str);
                    }
                    for(j=0;j<3;j++)
                        v[j]-=maps[i][j];
                    v[i]++;
                }
                fu=0;
                for(j=0;j<3;j++)
                {
                    if(v[j]>=maps[i][j])
                        fu++;
                }
                if(fu==3)
                {
                    str[str.size()-1]='a'+i;
                    for(j=0;j<3;j++)
                        v[j]-=maps[i][j];
                    v[i]++;
                    if(hsh.find(v)==hsh.end())
                    {
                        hsh[v]=1;
                        q.emplace(v,str);
                    }
                    v[i]--;
                    for(j=0;j<3;j++)
                        v[j]+=maps[i][j];
                }
            }
        }
        if(yay==0)
            printf("NO SOLUTION\n");
    }
}
