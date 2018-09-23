#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
int n,m;
vector<int> adj[51000];
queue<int> q;
char color[51000];
bool hsh[51000];
int main()
{
    scanf("%d %d",&n,&m);
    int i,j,k;
    for(i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //q.push(1);
    for(i=1;i<=n;i++)
    {
        color[i]=2;
    }
    int cot=1;
    //color[1]=1;
    int chck=0;
    int hi=0;
    for(k=1;k<=n;k++)
    {
        if(color[k]!=2)
        {
            //printf("F");
            continue;
        }
        color[k]=1;
        q.push(k);
        while(!q.empty())
        {
            chck=0;
            //printf("F");
            int idx=q.front();
            //printf("%d\n",idx);
            q.pop();
            for(i=0;i<adj[idx].size();i++)
            {
                chck=0;
                //printf("F");
                if(color[adj[idx][i]]!=2)
                {
                    //printf("%d\n",color[adj[idx][i]]);
                    //system("pause");
                    //printf("8=====D\n");
                    if(color[idx]==color[adj[idx][i]])
                    {
                        printf("-1\n");
                        exit(0);
                    }
                    else
                    {
                        chck=1;
                    }
                }
                if(chck==0)
                {
                    q.push(adj[idx][i]);
                    color[adj[idx][i]]=1-color[idx];
                }

                cot++;
            }
            hsh[idx]=1;
        }
        int a=0,b=0;
        for(i=1;i<=n;i++)
        {
            if(hsh[i]==1&&color[i]==1)
                a++;
            if(hsh[i]==1&&color[i]==0)
                b++;
        }
        hi+=max(a,b);
        //printf("%d\n",hi);
        memset(hsh,0,sizeof hsh);
    }
    /*while(!q.empty())
    {
        printf("%d",q.front());
        q.pop();
    }*/

    printf("%d",hi);
}
