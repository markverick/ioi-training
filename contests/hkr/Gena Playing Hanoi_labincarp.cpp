#include<bits/stdc++.h>
using namespace std;
int st,ed;
queue<int> q;
int mv[1100000];
int hsh[5];
int main()
{
    int i,j,k,n,a,tmp,X,Y;
    vector<int> x,y;
    scanf("%d",&n);
    st=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        st*=4;
        st+=a-1;
        x.emplace_back(a-1);
        y.emplace_back(a-1);
    }
    q.emplace(st);
    mv[st]=1;
    while(!q.empty())
    {
        X=q.front();
        if(X==0)
            break;
        tmp=X;
        i=n-1;
        while(i>=0)
        {
//            printf("%d %d\n",i,tmp);
            x[i--]=tmp%4;
            tmp/=4;
        }
//        system("pause");
        y=x;
        q.pop();
        memset(hsh,0,sizeof hsh);
        for(i=0;i<x.size();i++)
        {
            if(hsh[x[i]]==1)
                continue;
            for(j=0;j<4;j++)
            {
                if(hsh[j]==0&&j!=x[i])
                {
                    y[i]=j;
                    Y=0;
                    for(k=0;k<y.size();k++)
                    {
                        Y*=4;
                        Y+=y[k];
                    }
                    if(mv[Y]==0)
                    {
                        mv[Y]=mv[X]+1;
                        q.emplace(Y);
                    }
                    y[i]=x[i];
                }
            }
            hsh[x[i]]=1;
        }
    }
    printf("%d",mv[0]-1);
}
